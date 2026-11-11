#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Preferences.h>
#include <time.h>
#include "secrets.h"

// ---------- Hardware que ya has probado ----------
constexpr uint8_t WATER_PIN = 34; // SIG del Water Sensor. LOW = agua.
constexpr uint8_t BUZZER_PIN = 23; // SIG del Grove Buzzer.

// ---------- Ajustes ----------
constexpr uint32_t WET_CONFIRM_MS = 400;    // Anti-falsas alarmas
constexpr uint32_t DRY_CONFIRM_MS = 800;    // Evita finalizaciones por salpicaduras
constexpr uint32_t STATE_INTERVAL_MS = 2000;
constexpr uint32_t MQTT_RETRY_MS = 5000;
constexpr uint32_t WIFI_RETRY_MS = 10000;
constexpr uint8_t HISTORY_SIZE = 8;
constexpr char MQTT_SERVER[] = "broker.emqx.io";
constexpr uint16_t MQTT_PORT = 1883;       // Publico; solo para demostraciones

WiFiClient wifiClient;
PubSubClient mqtt(wifiClient);
Preferences preferences;

String topicState;
String topicEvent;
String topicHistory;
String topicConnection;
String topicCommands;

// ---------- Datos persistentes en la NVS del ESP32 ----------
struct LeakRecord {
  uint32_t id;
  uint32_t startUnix;             // 0 si no hubo sincronizacion NTP
  uint32_t endUnix;               // 0 si no hubo sincronizacion NTP
  uint32_t durationSeconds;
};

struct PersistentState {
  uint32_t magic;
  uint32_t leakCount;
  uint64_t totalLeakMillis;      // Solo duraciones de fugas finalizadas
  uint8_t recordsCount;
  uint8_t nextRecord;
  uint8_t reserved[2];
  LeakRecord records[HISTORY_SIZE];
};

constexpr uint32_t STORAGE_MAGIC = 0x4C470002; // LG v2
PersistentState stored{};
bool storageReady = false;

// ---------- Variables de operacion ----------
bool rawWet = false;              // Lectura instantanea
bool waterDetected = false;       // Lectura ya confirmada por tiempo
bool muted = false;
uint32_t rawChangedAt = 0;
uint32_t leakStartedAt = 0;
uint32_t leakStartUnix = 0;
uint32_t lastPublish = 0;
uint32_t lastMqttAttempt = 0;
uint32_t lastWifiAttempt = 0;
bool ntpConfigured = false;

// Prototipo de las funciones empleadas antes de su definicion
void publishState();
void publishHistory();
void updateBuzzer();

// Hora Unix en segundos. 0 significa "fecha no disponible".
uint32_t currentUnix() {
  const time_t now = time(nullptr);
  return now > 1700000000 ? static_cast<uint32_t>(now) : 0;
}

void saveStorage() {
  if (!storageReady) return;
  if (preferences.putBytes("data", &stored, sizeof(stored)) != sizeof(stored)) {
    Serial.println("ERROR: no se pudo guardar en NVS");
  }
}

void loadStorage() {
  storageReady = preferences.begin("leakguard", false);
  if (!storageReady) {
    Serial.println("ERROR: NVS no disponible; estadisticas solo en RAM");
    return;
  }

  if (preferences.getBytesLength("data") == sizeof(stored)) {
    PersistentState loaded{};
    if (preferences.getBytes("data", &loaded, sizeof(loaded)) == sizeof(loaded) &&
        loaded.magic == STORAGE_MAGIC &&
        loaded.recordsCount <= HISTORY_SIZE &&
        loaded.nextRecord < HISTORY_SIZE) {
      stored = loaded;
      return;
    }
  }

  stored = PersistentState{};
  stored.magic = STORAGE_MAGIC;
  saveStorage();
}

// Melodia ORIGINAL con ritmo de conga; no bloquea MQTT.
// void updateBuzzer() {
//   static const uint16_t notes[] = {
//     784, 0, 784, 988, 0, 880, 784, 0,
//     1047, 988, 784, 0, 880, 784, 0, 0
//   };
//   static const uint16_t times[] = {
//     130, 70, 130, 180, 80, 130, 180, 80,
//     150, 130, 200, 70, 130, 260, 150, 250
//   };
//   static size_t step = 0;
//   static uint32_t lastStepAt = 0;
//   static bool playing = false;

//   if (!waterDetected || muted) {
//     if (playing) noTone(BUZZER_PIN);
//     playing = false;
//     step = 0;
//     return;
//   }

//   const uint32_t now = millis();
//   if (!playing) {
//     playing = true;
//     step = 0;
//     lastStepAt = now;
//     tone(BUZZER_PIN, notes[0]);
//     return;
//   }

//   if (now - lastStepAt >= times[step]) {
//     lastStepAt = now;
//     step = (step + 1) % (sizeof(notes) / sizeof(notes[0]));
//     if (notes[step] == 0) noTone(BUZZER_PIN);
//     else tone(BUZZER_PIN, notes[step]);
//   }
// }

void updateBuzzer()
{
  // Alarma: PI - PI - PI - PI - pausa - repetir
  static const uint16_t notes[] = {
      2200, 0, 2200, 0, 2200, 0, 2200, 0};

  static const uint16_t times[] = {
      150, 150, 150, 150, 150, 150, 150, 650};

  static size_t step = 0;
  static uint32_t lastStepAt = 0;
  static bool playing = false;

  // Apagar inmediatamente si no hay fuga o está silenciado
  if (!waterDetected || muted)
  {
    noTone(BUZZER_PIN);
    playing = false;
    step = 0;
    return;
  }

  const uint32_t now = millis();

  // Comenzar el patrón desde el primer pitido
  if (!playing)
  {
    playing = true;
    step = 0;
    lastStepAt = now;
    tone(BUZZER_PIN, notes[0]);
    return;
  }

  // Avanzar al siguiente sonido sin bloquear el programa
  if (now - lastStepAt >= times[step])
  {
    lastStepAt = now;
    step = (step + 1) % (sizeof(notes) / sizeof(notes[0]));

    if (notes[step] == 0)
    {
      noTone(BUZZER_PIN);
    }
    else
    {
      tone(BUZZER_PIN, notes[step]);
    }
  }
}

uint32_t currentLeakSeconds(uint32_t now) {
  return waterDetected ? (now - leakStartedAt) / 1000UL : 0;
}

void publishState() {
  if (!mqtt.connected()) return;

  const uint32_t now = millis();
  const uint64_t allMs = stored.totalLeakMillis +
      (waterDetected ? static_cast<uint64_t>(now - leakStartedAt) : 0ULL);

  char payload[360];
  snprintf(payload, sizeof(payload),
    "{\"water_detected\":%s,\"buzzer\":%s,\"muted\":%s,"
    "\"leak_count\":%lu,\"current_leak_seconds\":%lu,"
    "\"total_leak_seconds\":%llu,\"updated_at_unix\":%lu}",
    waterDetected ? "true" : "false",
    waterDetected && !muted ? "true" : "false",
    muted ? "true" : "false",
    static_cast<unsigned long>(stored.leakCount),
    static_cast<unsigned long>(currentLeakSeconds(now)),
    static_cast<unsigned long long>(allMs / 1000ULL),
    static_cast<unsigned long>(currentUnix())
  );

  bool published = mqtt.publish(
      topicState.c_str(),
      payload,
      true);

  Serial.printf(
      "MQTT [%s] %s\n",
      published ? "OK" : "ERROR",
      topicState.c_str());

  Serial.println(payload);
}

void publishEvent(const char* type, uint32_t id, uint32_t when,
                  uint32_t durationSeconds = 0) {
  if (!mqtt.connected()) return;
  char payload[192];
  snprintf(payload, sizeof(payload),
    "{\"type\":\"%s\",\"id\":%lu,\"timestamp_unix\":%lu,"
    "\"duration_seconds\":%lu}",
    type,
    static_cast<unsigned long>(id),
    static_cast<unsigned long>(when),
    static_cast<unsigned long>(durationSeconds)
  );
  mqtt.publish(topicEvent.c_str(), payload, false); // Evento no retenido
  Serial.println(payload);
}

void publishHistory() {
  if (!mqtt.connected()) return;

  // Publicamos los ultimos 8 eventos finalizados; mas reciente primero.
  char payload[1400];
  size_t used = 0;
  int written = snprintf(payload, sizeof(payload),
      "{\"count\":%u,\"events\":[", stored.recordsCount);
  if (written < 0 || static_cast<size_t>(written) >= sizeof(payload)) return;
  used = static_cast<size_t>(written);

  for (uint8_t i = 0; i < stored.recordsCount; i++) {
    const uint8_t idx =
      (stored.nextRecord + HISTORY_SIZE - 1 - i) % HISTORY_SIZE;
    const LeakRecord &record = stored.records[idx];

    written = snprintf(payload + used, sizeof(payload) - used,
      "%s{\"id\":%lu,\"start_unix\":%lu,\"end_unix\":%lu,"
      "\"duration_seconds\":%lu}",
      i == 0 ? "" : ",",
      static_cast<unsigned long>(record.id),
      static_cast<unsigned long>(record.startUnix),
      static_cast<unsigned long>(record.endUnix),
      static_cast<unsigned long>(record.durationSeconds)
    );
    if (written < 0 || static_cast<size_t>(written) >= sizeof(payload) - used) {
      Serial.println("ERROR: historial excede el buffer JSON");
      return;
    }
    used += static_cast<size_t>(written);
  }

  written = snprintf(payload + used, sizeof(payload) - used, "]}");
  if (written < 0 || static_cast<size_t>(written) >= sizeof(payload) - used) return;

  if (!mqtt.publish(topicHistory.c_str(), payload, true)) {
    Serial.println("ERROR: no se pudo publicar el historial");
  }
}

// Transiciones del sensor, una vez vencido el filtro temporal.
void onWaterStateChanged(bool isWet, uint32_t now) {
  waterDetected = isWet;

  if (isWet) {
    // Nueva fuga confirmada
    muted = false;
    leakStartedAt = now;
    leakStartUnix = currentUnix();
    ++stored.leakCount;
    saveStorage();
    Serial.println("FUGA CONFIRMADA");
    publishEvent("LEAK_START", stored.leakCount, leakStartUnix);
  } else {
    // Fin de fuga confirmado
    const uint32_t elapsedMs = now - leakStartedAt;
    const uint32_t duration = elapsedMs / 1000UL;
    const uint32_t endUnix = currentUnix();
    uint32_t startUnix = leakStartUnix;
    if (startUnix == 0 && endUnix > duration) {
      startUnix = endUnix - duration; // Recupera hora si NTP sincronizo tarde
    }

    stored.totalLeakMillis += elapsedMs;
    stored.records[stored.nextRecord] =
        {stored.leakCount, startUnix, endUnix, duration};
    stored.nextRecord = (stored.nextRecord + 1) % HISTORY_SIZE;
    if (stored.recordsCount < HISTORY_SIZE) ++stored.recordsCount;
    saveStorage();
    muted = false;
    Serial.printf("FUGA FINALIZADA (%lu segundos)\n",
                  static_cast<unsigned long>(duration));
    publishEvent("LEAK_END", stored.leakCount, endUnix, duration);
    publishHistory();
  }

  updateBuzzer();
  publishState();
}

void processWaterSensor(uint32_t now) {
  const bool newRawWet = digitalRead(WATER_PIN) == LOW;
  if (newRawWet != rawWet) {
    rawWet = newRawWet;
    rawChangedAt = now;
  }

  if (rawWet != waterDetected) {
    const uint32_t requiredMs = rawWet ? WET_CONFIRM_MS : DRY_CONFIRM_MS;
    if (now - rawChangedAt >= requiredMs) {
      onWaterStateChanged(rawWet, now);
    }
  }
}

void mqttCallback(char* topic, byte* payload, unsigned int length) {
  if (topicCommands != topic || length == 0 || length > 40) return;

  char command[41];
  memcpy(command, payload, length);
  command[length] = '\0';
  String request(command);
  request.trim();
  request.toUpperCase();

  if (request == "SILENCE") {
    // No silenciar de antemano una futura fuga.
    if (waterDetected) muted = true;
    updateBuzzer();
    publishState();
  } else if (request == "UNMUTE") {
    muted = false;
    updateBuzzer();
    publishState();
  } else if (request == "GET_STATUS") {
    publishState();
  } else if (request == "GET_HISTORY") {
    publishHistory();
  }
}

void connectMqtt() {
  String clientId = "LeakGuard-" + WiFi.macAddress();
  clientId.replace(":", "");

  Serial.println("Conectando a MQTT...");
  const bool connected = mqtt.connect(
      clientId.c_str(), topicConnection.c_str(), 1, true, "offline");

  if (connected) {
    Serial.println("MQTT conectado");
    mqtt.subscribe(topicCommands.c_str(), 1);
    mqtt.publish(topicConnection.c_str(), "online", true);
    publishState();
    publishHistory();
  } else {
    Serial.printf("Error MQTT: %d\n", mqtt.state());
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(WATER_PIN, INPUT); // GPIO34 no tiene pull-up interno
  pinMode(BUZZER_PIN, OUTPUT);
  noTone(BUZZER_PIN);

  loadStorage();
  rawWet = digitalRead(WATER_PIN) == LOW;
  waterDetected = false; // Si arranca mojado, confirmar primero 400 ms
  rawChangedAt = millis();

  topicState = String(MQTT_TOPIC_ROOT) + "/state";
  topicEvent = String(MQTT_TOPIC_ROOT) + "/event";
  topicHistory = String(MQTT_TOPIC_ROOT) + "/history";
  topicConnection = String(MQTT_TOPIC_ROOT) + "/connection";
  topicCommands = String(MQTT_TOPIC_ROOT) + "/cmd";

  mqtt.setServer(MQTT_SERVER, MQTT_PORT);
  mqtt.setCallback(mqttCallback);
  mqtt.setKeepAlive(15);
  mqtt.setSocketTimeout(2);
  if (!mqtt.setBufferSize(2048)) {
    Serial.println("ERROR: no hay RAM para el buffer MQTT");
  }

  WiFi.mode(WIFI_STA);
  WiFi.setAutoReconnect(true);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.println("LeakGuard IoT Pro iniciado");
}

void loop() {
  const uint32_t now = millis();

  // Procesamiento local, independiente de la red.
  processWaterSensor(now);
  updateBuzzer();

  if (WiFi.status() == WL_CONNECTED) {
    if (!ntpConfigured) {
      configTime(0, 0, "pool.ntp.org", "time.google.com"); // UTC
      ntpConfigured = true;
    }

    if (!mqtt.connected()) {
      if (now - lastMqttAttempt >= MQTT_RETRY_MS) {
        lastMqttAttempt = now;
        connectMqtt();
      }
    } else {
      mqtt.loop();
      if (now - lastPublish >= STATE_INTERVAL_MS) {
        lastPublish = now;
        publishState();
      }
    }
  } else if (now - lastWifiAttempt >= WIFI_RETRY_MS) {
    lastWifiAttempt = now;
    WiFi.reconnect();
  }

  delay(20);
}
