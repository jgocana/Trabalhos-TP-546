# Trabalho IoT — LeakGuard

## Tema

**LeakGuard: Projeto e Implementação de um Sistema IoT para Detecção de Água, Monitoramento Remoto e Registro de Incidentes**

Este trabalho foi desenvolvido na disciplina **Internet das Coisas e Redes Veiculares (TP-546)** do **Instituto Nacional de Telecomunicações — Inatel**, como implementação prática com microcontrolador ESP32, comunicação MQTT e aplicativo Android.

## Autores

**José Antonio García Ocaña** — Matrícula 979 — [ORCID: 0000-0003-0816-8353](https://orcid.org/0000-0003-0816-8353)  
**Yaislin Bell Verdecia** — Matrícula 1005 — [ORCID: 0009-0000-7328-7864](https://orcid.org/0009-0000-7328-7864)  
**Martin Alonso Siffrin** — Matrícula 999 — [ORCID: 0009-0004-2686-2693](https://orcid.org/0009-0004-2686-2693)

Instituto Nacional de Telecomunicações — Inatel  
Santa Rita do Sapucaí, MG, Brasil.

## Objetivo

Desenvolver um sistema de **detecção localizada de presença de água** que combine resposta acústica no próprio dispositivo, supervisão em tempo real e registro persistente de incidentes. A solução permite acompanhar o sensor remotamente e emitir comandos por MQTT, preservando a detecção e o alarme locais quando a comunicação com a rede estiver indisponível.

## Solução desenvolvida

O **LeakGuard** é formado por três subsistemas integrados:

1. **Nó embarcado (ESP32):** lê o sensor de água, controla o buzzer, contabiliza incidentes e mantém registros locais em memória não volátil.
2. **Comunicação MQTT:** utiliza Wi-Fi e o broker de demonstração EMQX para distribuir estados, eventos, histórico e comandos entre os clientes.
3. **Aplicativo Android:** oferece dashboard, controle remoto, consulta a eventos, estatísticas e armazenamento histórico local.

O **MQTTX Web** é utilizado como cliente adicional de inspeção e teste das mensagens MQTT.

## Componentes e tecnologias

| Categoria | Componentes e tecnologias | Função |
| --- | --- | --- |
| Microcontrolador | ESP32 DOIT DevKit V1 | Leitura, processamento local e Wi-Fi |
| Sensor | Grove Water Sensor V1.1 — GPIO34 | Detecção de contato com água |
| Atuador | Grove Buzzer V1.2 — GPIO23 | Alarme sonoro local |
| Firmware | C++, PlatformIO, Arduino Framework, PubSubClient | Lógica embarcada e comunicação |
| Persistência embarcada | Preferences / NVS | Histórico circular de até oito incidentes |
| Mensageria | MQTT 3.1.1, EMQX | Publicação e assinatura de mensagens |
| Monitoramento | MQTTX Web | Diagnóstico e comandos MQTT |
| Android | Kotlin, Jetpack Compose, MVVM, Room e DataStore | Interface, histórico e preferências |

## Arquitetura funcional

```text
 Grove Water Sensor V1.1
          │ GPIO34
          ▼
       ESP32 ─── GPIO23 ───► Grove Buzzer V1.2
          │
          ├──► Preferences / NVS (histórico local)
          │
          ▼
      Wi-Fi / MQTT
          │
          ▼
      Broker EMQX
          │
          ├──────────────► MQTTX Web
          │                 (diagnóstico)
          │
          └──────────────► Aplicativo Android
                            (dashboard, comandos,
                             Room e estatísticas)
```

As mensagens de estado e eventos partem do ESP32 para os clientes. Os comandos publicados pelo Android ou MQTTX seguem pelo broker até o ESP32. A detecção e o acionamento local do buzzer não dependem da aplicação móvel.

## Funcionalidades

- Detecção de água com confirmação temporal de **400 ms** e retorno à condição seca após **800 ms**.
- Sinalização acústica local com execução não bloqueante.
- Publicação periódica de estados e eventos via MQTT.
- Comandos **`SILENCE`**, **`UNMUTE`**, **`GET_STATUS`** e **`GET_HISTORY`**.
- Histórico circular de oito incidentes no ESP32 e estatísticas de duração.
- Sincronização de tempo por NTP e uso de marcas temporais nos registros.
- Supervisão de conectividade e reconexão MQTT, com Last Will and Testament (LWT).
- Dashboard Android, histórico persistente com Room e atualização de estados.

### Tópicos MQTT

Prefixo do dispositivo utilizado na implementação:

```text
leakguard/jgocana-yverdecia-iot-device01
```

| Sufixo | Finalidade |
| --- | --- |
| `/state` | Estado atual, buzzer e estatísticas |
| `/event` | Início e encerramento de incidentes |
| `/history` | Histórico recente armazenado no ESP32 |
| `/connection` | Disponibilidade do dispositivo |
| `/cmd` | Comandos de controle e consulta |

O broker público **`broker.emqx.io`** é utilizado para fins de demonstração acadêmica. Para implantação permanente, são necessários controles apropriados de autenticação, privacidade e segurança da comunicação.

## Materiais do trabalho

### Documento e apresentação

- [Documento de apresentação do projeto (PDF)](./documento/LeakGuard%20%20Apresenta%C3%A7%C3%A3o%20do%20Projeto%20IoT%20com%20ESP32%2C%20MQTT%20e%20Android.pdf)
- [Apresentação do trabalho (PowerPoint editável)](./presentac%C3%A3o/LeakGuard_IoT.pptx)

### Aplicativo Android

- [Aplicativo LeakGuard — APK de instalação](./aplicativo/br.inatel.mtel.leakguardiot-v1.0.0-release.apk)
- [Código-fonte do projeto Android (ZIP)](./projetos/Android/LeakGuard_Iot-master.zip)

### Firmware ESP32

- [Projeto PlatformIO / Arduino](./projetos/IoT/trabalho_Iot/)
- [Código-fonte principal (`main.cpp`)](./projetos/IoT/trabalho_Iot/src/main.cpp)
- [Configuração PlatformIO (`platformio.ini`)](./projetos/IoT/trabalho_Iot/platformio.ini)

### Vídeos

- **Apresentação do projeto LeakGuard:** [Assistir no YouTube](https://youtu.be/vbGF-0o2YHY).
- **Demonstração prática do experimento com ESP32, sensor de água, MQTT e Android:** [Assistir ao YouTube Short](https://www.youtube.com/shorts/WqVsKRFApew).

## Execução e reprodução

**ESP32:** abra a pasta `projetos/IoT/trabalho_Iot/` com PlatformIO, configure os dados de rede e MQTT em um arquivo local de configuração e grave o firmware na placa ESP32 DOIT DevKit V1. Consulte `platformio.ini` para as dependências utilizadas.

**Android:** instale a APK disponível em `aplicativo/` em um dispositivo compatível ou abra o projeto Android após extrair o arquivo ZIP. Configure a conexão MQTT conforme o broker e o identificador usados pelo ESP32.

**MQTTX:** conecte-se ao broker da demonstração e assine `leakguard/jgocana-yverdecia-iot-device01/#` para acompanhar estados, eventos e histórico; utilize o tópico `/cmd` para os comandos descritos.

> **Nota sobre credenciais:** não inclua senhas de Wi-Fi, tokens ou segredos reais no controle de versão. Use variáveis locais ou um arquivo de configuração ignorado pelo Git, acompanhado de um exemplo sem credenciais.

## Organização dos arquivos

```text
Trabalho_IoT/
├── README.md
├── aplicativo/
│   └── br.inatel.mtel.leakguardiot-v1.0.0-release.apk
├── documento/
│   └── LeakGuard  Apresentação do Projeto IoT com ESP32, MQTT e Android.pdf
├── presentacão/
│   └── LeakGuard_IoT.pptx
└── projetos/
    ├── Android/
    │   └── LeakGuard_Iot-master.zip
    └── IoT/
        └── trabalho_Iot/
            ├── platformio.ini
            ├── include/
            ├── lib/
            ├── src/
            │   └── main.cpp
            └── test/
```

## Finalidade

O material possui finalidade **acadêmica** e reúne a implementação embarcada, o aplicativo móvel, a apresentação e os arquivos necessários à documentação do trabalho da disciplina TP-546.
