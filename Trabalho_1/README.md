# Trabalho 1 — Redes de Sensores Sem Fio aplicadas à Agricultura de Precisão

## Tema

**Aplicação de Redes de Sensores Sem Fio para Monitoramento da Umidade do Solo e Apoio à Irrigação de Precisão**

Este trabalho é desenvolvido no contexto da disciplina **Internet das Coisas e Redes Veiculares (TP-546)** do Instituto Nacional de Telecomunicações — Inatel.

## Autores

**José Antonio García Ocaña**  
Matrícula: 979  
Instituto Nacional de Telecomunicações — Inatel

**Yaislin Bell Verdecia**  
Matrícula: 1005  
Instituto Nacional de Telecomunicações — Inatel

Santa Rita do Sapucaí, MG, Brasil.

## Objetivo

O objetivo do trabalho é estudar a utilização de **Redes de Sensores Sem Fio (RSSF/WSN)** em sistemas de agricultura de precisão, com foco no **monitoramento distribuído da umidade do solo**.

A aplicação proposta considera a distribuição de nós sensores em uma área agrícola para coletar informações do solo e do ambiente e transmiti-las por meio de uma rede sem fio até um gateway ou plataforma de monitoramento.

Essas informações podem auxiliar na tomada de decisão relacionada à irrigação, permitindo um uso mais eficiente dos recursos hídricos.

## Escopo do trabalho

O estudo aborda os seguintes aspectos:

* conceitos de agricultura de precisão;
* fundamentos de Redes de Sensores Sem Fio;
* aplicação de RSSF no ambiente agrícola;
* monitoramento da umidade do solo;
* sensores de solo e sensores ambientais;
* organização dos nós sensores;
* tecnologias de comunicação sem fio;
* LoRa e LoRaWAN;
* gateway e integração com plataformas IoT;
* consumo energético dos nós;
* cobertura e propagação do sinal;
* precisão e calibração dos sensores;
* custos e desafios de implantação.

## Arquitetura conceitual

A solução estudada segue, de forma simplificada, a seguinte arquitetura:

```text
Sensores de solo e ambiente
           │
           ▼
       Nó Sensor
           │
           │ LoRa / LoRaWAN
           ▼
        Gateway
           │
           ▼
     Internet / IoT
           │
           ▼
 Plataforma de Monitoramento
           │
           ▼
 Apoio à decisão de irrigação
```

## Documento

O relatório é desenvolvido utilizando o formato de artigo científico **IEEE Conference**.

* [Relatório — Trabalho 1](./documento/Trabalho_1_RSSF_Agricultura_Precisao.pdf)

## Referências principais

A bibliografia foi selecionada com foco em **RSSF/WSN, agricultura de precisão, sensores de umidade do solo, LoRa/LoRaWAN e implementações experimentais**.

Os artigos utilizados no desenvolvimento do trabalho também estão armazenados neste repositório para facilitar a consulta e a organização das fontes bibliográficas.

### Redes de sensores e agricultura inteligente

1. **Mowla, M. N. et al. (2023).**
   *Internet of Things and Wireless Sensor Networks for Smart Agriculture Applications: A Survey.*
   IEEE Access, vol. 11, pp. 145813–145852.

   * [IEEE Xplore](https://ieeexplore.ieee.org/document/10371307/)
   * [DOI](https://doi.org/10.1109/ACCESS.2023.3346299)
   * [PDF no repositório](./referencias/01_Mowla_2023_IoT_WSN_Smart_Agriculture.pdf)

2. **Al-Ani, N. M. K. et al. (2025).**
   *A Comprehensive Review of Using WSNs and Drones for Improving Crop Production in Precision Agriculture.*
   IET Wireless Sensor Systems, vol. 15.

   * [Wiley Online Library](https://onlinelibrary.wiley.com/doi/abs/10.1049/wss2.70019)
   * [DOI](https://doi.org/10.1049/wss2.70019)
   * [PDF no repositório](./referencias/02_Al-Ani_2025_WSN_Precision_Agriculture.pdf)

### Monitoramento da umidade do solo

3. **Lloret, J.; Sendra, S.; Garcia, L.; Jimenez, J. M. (2021).**
   *A Wireless Sensor Network Deployment for Soil Moisture Monitoring in Precision Agriculture.*
   Sensors, vol. 21, no. 21, 7243.

   * [MDPI Sensors](https://www.mdpi.com/1424-8220/21/21/7243)
   * [DOI](https://doi.org/10.3390/s21217243)
   * [PDF no repositório](./referencias/03_Lloret_2021_Soil_Moisture_WSN.pdf)

4. **Silva, A. C. et al. (2024).**
   *Plataforma Digital Integrada a Rede de Sensores Sem Fio para Monitoramento Contínuo da Umidade do Solo.*
   Workshop de Computação Aplicada à Gestão do Meio Ambiente e Recursos Naturais — WCAMA, pp. 189–198.

   * [Sociedade Brasileira de Computação](https://sol.sbc.org.br/index.php/wcama/article/view/29431)
   * [DOI](https://doi.org/10.5753/wcama.2024.3208)
   * [PDF no repositório](./referencias/04_Silva_2024_RSSF_Umidade_Solo.pdf)

### Sensores

5. **Kashyap, B.; Kumar, R. (2021).**
   *Sensing Methodologies in Agriculture for Soil Moisture and Nutrient Monitoring.*
   IEEE Access, vol. 9, pp. 14095–14121.

   * [IEEE Xplore](https://ieeexplore.ieee.org/document/9328258/)
   * [DOI](https://doi.org/10.1109/ACCESS.2021.3052478)
   * [PDF no repositório](./referencias/05_Kashyap_Kumar_2021_Soil_Moisture_Sensing.pdf)

6. **Soussi, A. et al. (2024).**
   *Smart Sensors and Smart Data for Precision Agriculture: A Review.*
   Sensors, vol. 24, no. 8, 2647.

   * [PubMed Central](https://pmc.ncbi.nlm.nih.gov/articles/PMC11053448/)
   * [DOI](https://doi.org/10.3390/s24082647)
   * [PDF no repositório](./referencias/06_Soussi_2024_Smart_Sensors_Precision_Agriculture.pdf)

### LoRa e monitoramento agrícola

7. **Singh, D. K. et al. (2022).**
   *LoRa Based Intelligent Soil and Weather Condition Monitoring with Internet of Things for Precision Agriculture in Smart Cities.*
   IET Communications, vol. 16, no. 5, pp. 604–618.

   * [Wiley Online Library](https://onlinelibrary.wiley.com/doi/abs/10.1049/cmu2.12352)
   * [DOI](https://doi.org/10.1049/cmu2.12352)
   * [PDF no repositório](./referencias/07_Singh_2022_LoRa_Soil_Weather.pdf)

### Agricultura de precisão

8. **Inamasu, R. et al. (2024).**
   *Agricultura de precisão: perspectiva histórica e de constante transformação.*
   pp. 17–32.

   * [DOI](https://doi.org/10.4322/978-65-86819-38-0.1000003)
   * [PDF no repositório](./referencias/08_Inamasu_2024_Agricultura_Precisao.pdf)

9. **Bayih, A. Z.; Morales, J.; Assabie, Y.; De By, R. A. (2022).**
   *Utilization of Internet of Things and Wireless Sensor Networks for Sustainable Smallholder Agriculture.*
   Sensors, vol. 22, no. 9, 3273.

   * [MDPI Sensors](https://www.mdpi.com/1424-8220/22/9/3273)
   * [DOI](https://doi.org/10.3390/s22093273)
   * [PDF no repositório](./referencias/09_Bayih_2022_IoT_WSN_Smallholder_Agriculture.pdf)
