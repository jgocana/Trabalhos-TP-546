# Trabalhos-TP-546

Repositório destinado aos trabalhos da disciplina **Internet das Coisas e Redes Veiculares (TP-546)** do **Instituto Nacional de Telecomunicações — Inatel**.

O repositório reúne estudos, artigos científicos, relatórios e materiais de apoio relacionados a **Internet das Coisas (IoT)**, **Redes de Sensores Sem Fio (RSSF/WSN)**, agricultura inteligente, robótica agrícola, segurança de redes IoT, **LoRa/LoRaWAN**, comunicação direta entre dispositivos e satélites (**DtS-IoT**) e implementação de sistemas IoT com **ESP32, MQTT e Android**.

## Autores

- **José Antonio García Ocaña** — Matrícula 979 — [ORCID](https://orcid.org/0000-0003-0816-8353)
- **Yaislin Bell Verdecia** — Matrícula 1005 — [ORCID](https://orcid.org/0009-0000-7328-7864)

Instituto Nacional de Telecomunicações — Inatel  
Santa Rita do Sapucaí, MG, Brasil

## Organização do repositório

Cada trabalho possui sua própria pasta e um `README.md` específico. Os Trabalhos 1, 2 e 3 concentram seus relatórios em `documento/` e as fontes utilizadas em `referencias/`. O **Trabalho IoT — LeakGuard** reúne os materiais da implementação prática: aplicativo Android, documento de apresentação, PowerPoint e projetos de software embarcado e móvel.

```text
Trabalhos-TP-546/
├── README.md
├── Trabalho_1/
│   ├── README.md
│   ├── documento/
│   └── referencias/
├── Trabalho_2/
│   ├── README.md
│   ├── documento/
│   └── referencias/
├── Trabalho_3/
│   ├── README.md
│   ├── documento/
│   └── referencias/
└── Trabalho_IoT/
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

## Trabalhos

| Trabalho | Tema | Situação | Documentação |
| --- | --- | --- | --- |
| **Trabalho 1** | Redes de Sensores Sem Fio aplicadas à Agricultura de Precisão | Concluído | [Acessar Trabalho 1](./Trabalho_1/README.md) |
| **Trabalho 2** | Agricultura Inteligente na Prática: estudo de caso do Solix Sprayer na Tereos | Concluído | [Acessar Trabalho 2](./Trabalho_2/README.md) |
| **Trabalho 3** | Segurança de beacons LoRaWAN Class B em cenários DtS-IoT: spoofing e mitigação | Concluído | [Acessar Trabalho 3](./Trabalho_3/README.md) |
| **Trabalho IoT** | LeakGuard: sistema de detecção de água, monitoramento remoto e registro de incidentes | Concluído | [Acessar Trabalho IoT](./Trabalho_IoT/README.md) |

## Trabalho 1 — Redes de Sensores Sem Fio

O primeiro trabalho aborda a aplicação de **Redes de Sensores Sem Fio no monitoramento da umidade do solo e no apoio à irrigação de precisão**.

O estudo inclui conceitos de agricultura de precisão, RSSF/WSN, sensores de umidade do solo, LoRa/LoRaWAN, gateways, integração com plataformas IoT e desafios relacionados a energia, cobertura, calibração e custos.

- [Documentação completa do Trabalho 1](./Trabalho_1/README.md)
- [Relatório do Trabalho 1](./Trabalho_1/documento/Trabalho_1_RSSF_Agricultura_Precisao.pdf)

## Trabalho 2 — Agricultura Inteligente na Prática

O segundo trabalho apresenta um **estudo de caso de uma aplicação real de IoT na agricultura**, analisando a utilização do **Solix Sprayer**, da Solinftec, na unidade Cruz Alta da Tereos, em Olímpia, São Paulo.

O estudo aborda agricultura inteligente, robótica agrícola, visão computacional, inteligência artificial, posicionamento GNSS/RTK, pulverização seletiva, conectividade, resultados da implantação, benefícios e limitações.

- [Documentação completa do Trabalho 2](./Trabalho_2/README.md)
- [Relatório do Trabalho 2](./Trabalho_2/documento/Trabalho_2_Agricultura_Inteligente_Solix_Tereos.pdf)

## Trabalho 3 — Segurança de Beacons LoRaWAN Class B em Cenários DtS-IoT

O terceiro trabalho analisa a ausência de autenticação criptográfica dos **beacons LoRaWAN Class B** e a exploração dessa vulnerabilidade por meio de **beacon spoofing**, com ênfase em **beacon drifting**. Apresenta o funcionamento da sincronização Class B, as evidências de ataque documentadas na literatura e mecanismos de prevenção, detecção, recuperação e resiliência.

O estudo também contextualiza o emprego de beacons como indicadores de cobertura em arquiteturas **Direct-to-Satellite IoT (DtS-IoT)** e discute as implicações e limitações da transferência de contramedidas de redes terrestres para enlaces com gateways orbitais. Não confunde os resultados experimentais de segurança em Class B terrestre com uma validação de ataque diretamente em enlace satelital.

- [Documentação completa do Trabalho 3 e bibliografia numerada](./Trabalho_3/README.md)
- [Relatório do Trabalho 3](./Trabalho_3/documento/Trabalho_3_Seguranca_Beacons_LoRaWAN_DtS-IoT.pdf)

## Trabalho IoT — LeakGuard

O **LeakGuard** é uma implementação prática de um sistema IoT para detecção localizada de presença de água, com atuação acústica por **ESP32**, transmissão de dados via **MQTT** e supervisão remota por **MQTTX Web** e aplicativo **Android**.

O nó embarcado utiliza o sensor **Grove Water Sensor V1.1** e o atuador **Grove Buzzer V1.2** para reconhecer a presença de água e emitir alertas locais. A arquitetura contempla monitoramento, comandos remotos, registro de incidentes e histórico persistente, com armazenamento no ESP32 e no aplicativo. Os materiais disponíveis incluem código-fonte do firmware em PlatformIO, projeto Android, APK de instalação, apresentação editável e documento de apoio.

- [Documentação completa do Trabalho IoT](./Trabalho_IoT/README.md)
- [Documento de apresentação (PDF)](./Trabalho_IoT/documento/LeakGuard%20%20Apresenta%C3%A7%C3%A3o%20do%20Projeto%20IoT%20com%20ESP32%2C%20MQTT%20e%20Android.pdf)
- [Apresentação em PowerPoint (PPTX)](./Trabalho_IoT/presentac%C3%A3o/LeakGuard_IoT.pptx)
- [Aplicativo Android — APK](./Trabalho_IoT/aplicativo/br.inatel.mtel.leakguardiot-v1.0.0-release.apk)
- [Projeto Android (ZIP)](./Trabalho_IoT/projetos/Android/LeakGuard_Iot-master.zip)
- [Projeto ESP32 / PlatformIO](./Trabalho_IoT/projetos/IoT/trabalho_Iot/)
- [Vídeo de apresentação do LeakGuard (YouTube)](https://youtu.be/vbGF-0o2YHY)
- [Vídeo de demonstração prática do experimento (YouTube Shorts)](https://www.youtube.com/shorts/WqVsKRFApew)

## Licença e uso

Este repositório possui finalidade **acadêmica**, sendo utilizado para organização e desenvolvimento dos trabalhos da disciplina TP-546. Os artigos e documentos de terceiros mantêm os direitos de seus respectivos autores e editoras.
