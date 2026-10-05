# Trabalho 3 — Segurança de Beacons LoRaWAN Class B em Cenários DtS-IoT

## Tema

**Segurança de Beacons LoRaWAN Class B em Cenários DtS-IoT: Ataques de Spoofing e Mecanismos de Mitigação**

Este trabalho integra a disciplina **Internet das Coisas e Redes Veiculares (TP-546)** do **Instituto Nacional de Telecomunicações — Inatel**.

## Autores

**José Antonio García Ocaña** — Matrícula 979 — [ORCID: 0000-0003-0816-8353](https://orcid.org/0000-0003-0816-8353)  
**Yaislin Bell Verdecia** — Matrícula 1005 — [ORCID: 0009-0000-7328-7864](https://orcid.org/0009-0000-7328-7864)

Instituto Nacional de Telecomunicações — Inatel  
Santa Rita do Sapucaí, MG, Brasil.

## Objetivo

Analisar a vulnerabilidade decorrente da ausência de autenticação criptográfica dos **beacons LoRaWAN Class B**, descrevendo o ataque de **beacon spoofing**, especialmente sua variante progressiva **beacon drifting**, e discutindo mecanismos de prevenção, detecção, recuperação e resiliência. A análise considera também arquiteturas **Direct-to-Satellite Internet of Things (DtS-IoT)** nas quais a recepção de um beacon pode ser utilizada para identificar uma oportunidade de contato com um gateway embarcado em satélite de órbita terrestre baixa (LEO).

## Contextualização e escopo

No funcionamento convencional de LoRaWAN Class B, beacons periódicos fornecem aos dispositivos uma referência temporal para aquisição de sincronização e cálculo das janelas programadas de recepção (*ping slots*). O formato de beacon previsto na especificação LoRaWAN 1.1 possui campos de **Cyclic Redundancy Check (CRC)** para detecção de erros, mas não autentica criptograficamente sua origem.

O estudo apresenta a sequência de falsificação da referência temporal e de deslocamento progressivo dos beacons, apoiando-se na especificação e em resultados publicados de modelagem, experimentação com hardware e simulação. Em propostas DtS-IoT que reutilizam o beacon como indicação de cobertura, a mesma dependência cria implicações adicionais para a decisão de quando transmitir em uplink.

**Delimitação:** os resultados experimentais de beacon drifting citados na bibliografia referem-se à operação LoRaWAN Class B. As consequências para a detecção de cobertura em DtS-IoT são discutidas como implicações técnicas dessas arquiteturas, não como resultados de um ensaio de ataque com gateway orbital.

O relatório contempla:

- funcionamento dos beacons, sua aquisição e acompanhamento pelos dispositivos Class B;
- sincronização, periodicidade e cálculo dos *ping slots*;
- utilização de beacons para detecção de oportunidades de comunicação DtS-IoT;
- panorama de ameaças e desafios de segurança em DtS-IoT;
- ausência de autenticação, modelo de ameaça e execução de *beacon spoofing* / *beacon drifting*;
- evidências experimentais publicadas e efeitos sobre a disponibilidade;
- autenticação de beacons, detecção por SNR/FCnt, contingência em Class A e diversidade de configuração;
- compromissos energéticos e operacionais das contramedidas no contexto satelital.

## Documento

Relatório em português, organizado em formato de artigo científico **IEEE Conference**.

- [Trabalho 3 — Segurança de Beacons LoRaWAN Class B em Cenários DtS-IoT (PDF)](./documento/Trabalho_3_Seguranca_Beacons_LoRaWAN_DtS-IoT.pdf)

## Referências bibliográficas

Os documentos da pasta `referencias/` seguem a **mesma numeração da lista de referências do relatório**, para facilitar a correspondência entre citações e arquivos. Os títulos originais das publicações foram preservados.

### DtS-IoT, detecção de cobertura e comunicação satelital

1. **Akar, S. et al. (2026).** *Direct-to-Satellite Internet of Things (DtS-IoT): A Tutorial Review on Architectures, Protocols, and Future Directions.* Frontiers in Communications and Networks.  
   [PDF no repositório](./referencias/01_Akar_2026_DtS_IoT_Tutorial_Review.pdf)

2. **Al Mojamed, M. (2024).** *Beacon-Based Uplink Transmission for LoRaWAN Direct to LEO Satellite Internet of Things.* International Journal of Computer Networks & Communications, vol. 16, n. 5, pp. 43–58.  
   [PDF no repositório](./referencias/02_Al_Mojamed_2024_Beacon_Based_Uplink_LoRaWAN.pdf)

3. **Fraire, J. A. et al. (2026).** *Blind vs. Satellite-Detect Uplink in LEO Direct-to-Satellite IoT: An Analytical Threshold.* IEEE Transactions on Vehicular Technology.  
   [PDF no repositório](./referencias/03_Fraire_2026_Blind_vs_Satellite_Detect_Uplink.pdf)

4. **LoRa Alliance (2017).** *LoRaWAN 1.1 Specification.* Especificação técnica do protocolo, incluindo operação Class B e estrutura dos beacons.  
   [PDF no repositório](./referencias/04_LoRa_Alliance_2017_LoRaWAN_1_1_Specification.pdf)

5. **Rolland, F. et al. (2025).** *Achieving Reduced Latency and Energy Efficiency in Direct-to-Satellite LoRaWAN Communications.* IEEE WFCS 2025.  
   [PDF no repositório](./referencias/05_Rolland_2025_Energy_Efficient_DtS_LoRaWAN.pdf)

### Segurança de LoRaWAN e beacon spoofing

6. **van Es, E.; Vranken, H.; Hommersom, A. (2018).** *Denial-of-Service Attacks on LoRaWAN.* ARES 2018.  
   [PDF no repositório](./referencias/06_Van_Es_2018_DoS_Attacks_LoRaWAN.pdf)

7. **Hessel, F.; Almon, L.; Álvarez, F. (2020).** *ChirpOTLE: A Framework for Practical LoRaWAN Security Evaluation.* ACM WiSec 2020, pp. 306–316.  
   [PDF no repositório](./referencias/07_Hessel_2020_ChirpOTLE_Beacon_Spoofing.pdf)

### Sincronização Class B e integração NTN

8. **Amador, M. Á. et al. (2026).** *Experimental Analysis of LoRaWAN Class B Synchronization: Towards NTN-Integrated IoT Networks.* Computer Networks, vol. 282, art. 112268.  
   [PDF no repositório](./referencias/08_Amador_2026_Class_B_Synchronization_NTN.pdf)

9. **Scalambrin, L.; Zanella, A.; Vilajosana, X. (2025).** *A Lightweight Algorithm for Efficient Synchronization in LoRaWAN Class-B Networks.* IEEE Internet of Things Journal, vol. 12, n. 16, pp. 32749–32764.  
   [PDF no repositório](./referencias/09_Scalambrin_2025_Lightweight_Class_B_Synchronization.pdf)

### Segurança em NTN e avaliações complementares

10. **Amodu, O. A. et al. (2026).** *Machine Learning-Enabled NTN-Assisted IoT: Mapping the Security Landscape.* Computers, Materials & Continua. O escopo da publicação é NTN-IoT em sentido amplo, não exclusivamente DtS-IoT.  
    [PDF no repositório](./referencias/10_Amodu_2026_NTN_IoT_Security_Landscape.pdf)

11. **Hessel, F.; Almon, L.; Hollick, M. (2023).** *LoRaWAN Security: An Evolvable Survey on Vulnerabilities, Attacks and their Systematic Mitigation.* ACM Transactions on Sensor Networks, vol. 18, n. 4.  
    [PDF no repositório](./referencias/11_Hessel_2023_LoRaWAN_Security_Survey.pdf)

12. **Ariyawansa, J. et al. (2025).** *Effects of Beacon Spoofing Attacks on Various LoRaWAN Network Devices.* IEEE SmartIoT 2025.  
    [PDF no repositório](./referencias/12_Ariyawansa_2025_Beacon_Spoofing_LoRaWAN.pdf)

## Organização dos arquivos

```text
Trabalho_3/
├── README.md
├── documento/
│   └── Trabalho_3_Seguranca_Beacons_LoRaWAN_DtS-IoT.pdf
└── referencias/
    ├── 01_Akar_2026_DtS_IoT_Tutorial_Review.pdf
    ├── 02_Al_Mojamed_2024_Beacon_Based_Uplink_LoRaWAN.pdf
    ├── 03_Fraire_2026_Blind_vs_Satellite_Detect_Uplink.pdf
    ├── 04_LoRa_Alliance_2017_LoRaWAN_1_1_Specification.pdf
    ├── 05_Rolland_2025_Energy_Efficient_DtS_LoRaWAN.pdf
    ├── 06_Van_Es_2018_DoS_Attacks_LoRaWAN.pdf
    ├── 07_Hessel_2020_ChirpOTLE_Beacon_Spoofing.pdf
    ├── 08_Amador_2026_Class_B_Synchronization_NTN.pdf
    ├── 09_Scalambrin_2025_Lightweight_Class_B_Synchronization.pdf
    ├── 10_Amodu_2026_NTN_IoT_Security_Landscape.pdf
    ├── 11_Hessel_2023_LoRaWAN_Security_Survey.pdf
    └── 12_Ariyawansa_2025_Beacon_Spoofing_LoRaWAN.pdf
```

## Finalidade

Material de finalidade **acadêmica**, reunindo o relatório e as fontes bibliográficas utilizadas no Trabalho 3 da disciplina TP-546.
