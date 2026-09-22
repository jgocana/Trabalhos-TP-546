# Trabalho 2 — Agricultura Inteligente na Prática

## Tema

**Agricultura Inteligente na Prática: Estudo de Caso do Solix Sprayer na Tereos**

Este trabalho foi desenvolvido no contexto da disciplina **Internet das Coisas e Redes Veiculares (TP-546)** do Instituto Nacional de Telecomunicações — Inatel.

## Autores

**Yaislin Bell Verdecia**  
Matrícula: 1005  
Instituto Nacional de Telecomunicações — Inatel

**José Antonio García Ocaña**  
Matrícula: 979  
Instituto Nacional de Telecomunicações — Inatel

Santa Rita do Sapucaí, MG, Brasil.

## Objetivo

O trabalho analisa um **caso real de aplicação de Internet das Coisas na agricultura**, considerando a utilização do robô agrícola **Solix Sprayer**, desenvolvido pela Solinftec, na unidade Cruz Alta da Tereos, localizada em Olímpia, São Paulo.

A implantação utiliza visão computacional, inteligência artificial, posicionamento de alta precisão e pulverização seletiva para identificar plantas daninhas e realizar aplicações localizadas de herbicidas em canaviais.

## Estudo de caso

A Tereos anunciou, em dezembro de 2023, a aquisição de duas plataformas Solix Sprayer para a unidade Cruz Alta. As plataformas iniciaram operação experimental em abril de 2024.

Entre os resultados divulgados para os primeiros testes está uma redução de aproximadamente **50% no uso de defensivos agrícolas**. O trabalho trata esse valor no contexto específico do projeto-piloto e também discute fatores que podem influenciar o desempenho da pulverização seletiva em diferentes ambientes agrícolas.

Como evidência complementar de expansão da tecnologia, o artigo também apresenta a utilização do Solix em outras propriedades brasileiras, incluindo as Fazendas Reunidas Baumgart, em Goiás.

## Escopo do trabalho

O estudo aborda os seguintes aspectos:

* agricultura inteligente e Agricultura 4.0;
* Internet das Coisas aplicada ao ambiente agrícola;
* robótica agrícola autônoma;
* manejo localizado de plantas daninhas;
* visão computacional e redes neurais convolucionais;
* posicionamento GNSS com correção RTK;
* navegação autônoma em ambientes agrícolas;
* telemetria e conectividade;
* pulverização seletiva por eletroválvulas;
* energia e autonomia operacional;
* resultados observados na implantação da Tereos;
* benefícios técnicos, operacionais e ambientais;
* limitações e desafios de implementação;
* evidências de expansão comercial da plataforma.

## Arquitetura funcional

A solução analisada pode ser representada, de forma simplificada, pelo seguinte fluxo:

```text
Ambiente agrícola
       │
       ▼
Percepção
Câmeras e sensores
       │
       ▼
Posicionamento e navegação
GNSS/RTK + visão computacional
       │
       ▼
Processamento e IA
Detecção e classificação
       │
       ▼
Tomada de decisão
       │
       ▼
Atuação
Pulverização seletiva
       │
       └──────────────► Ambiente agrícola

Processamento/IA
       │
       ▼
Comunicação e telemetria
       │
       ▼
Infraestrutura de gerenciamento
```

## Documento

O relatório foi desenvolvido em formato de artigo científico **IEEE Conference**.

* [Relatório — Trabalho 2](./documento/Trabalho_2_Agricultura_Inteligente_Solix_Tereos.pdf)

## Referências bibliográficas

Os arquivos da pasta `referencias/` seguem a mesma numeração utilizada no artigo. Quando a referência é uma página institucional ou matéria online, o link original é mantido juntamente com a cópia em PDF quando disponível.

### Agricultura inteligente, IoT e robótica agrícola

1. **Pivoto, D. et al. (2023).**  
   *Smart Farming in Brazil: An Overview of Technology, Adoption and Farmer Perception.*  
   Revista Brasileira de Gestão e Desenvolvimento Regional, vol. 19, no. 1, pp. 85–100.  
   * [PDF no repositório](./referencias/01_Pivoto_2023_Smart_Farming_Brazil.pdf)

2. **Sharma, K.; Shivandu (2024).**  
   *Integrating Artificial Intelligence and Internet of Things (IoT) for Enhanced Crop Monitoring and Management in Precision Agriculture.*  
   Sensors International, vol. 5, 100292.  
   * [PDF no repositório](./referencias/02_Sharma_2024_AI_IoT_Precision_Agriculture.pdf)

3. **Oliveira, A. I. S. et al. (2019).**  
   *On the Intelligent Control Design of an Agricultural Mobile Robot for Cotton Crop Monitoring.*  
   2019 Developments in eSystems Engineering (DeSE), IEEE.  
   * [PDF no repositório](./referencias/03_Oliveira_2019_Agricultural_Mobile_Robot_Cotton.pdf)

### Manejo de plantas daninhas e pulverização seletiva

4. **Upadhyay, A. et al. (2024).**  
   *Advances in Ground Robotic Technologies for Site-Specific Weed Management in Precision Agriculture: A Review.*  
   Computers and Electronics in Agriculture, vol. 225, 109363.  
   * [PDF no repositório](./referencias/04_Upadhyay_2024_Robotic_Weed_Management.pdf)

5. **Vijayakumar, V. et al. (2023).**  
   *Smart Spraying Technologies for Precision Weed Management: A Review.*  
   Smart Agricultural Technology, vol. 6, 100337.  
   * [PDF no repositório](./referencias/05_Vijayakumar_2023_Smart_Spraying_Weed_Management.pdf)

### Navegação autônoma e percepção

6. **Tian, Y. et al. (2023).**  
   *Design and Experiment of an Integrated Navigation System for a Paddy Field Scouting Robot.*  
   Computers and Electronics in Agriculture, vol. 214, 108336.  
   * [PDF no repositório](./referencias/06_Tian_2023_Integrated_Navigation_Agricultural_Robot.pdf)

9. **Martins, F. F. et al. (2021).**  
   *Sistema de navegação autônoma para o robô agrícola Soybot.*  
   XV Simpósio Brasileiro de Automação Inteligente (SBAI 2021).  
   * [PDF no repositório](./referencias/09_Martins_2021_Soybot_Navegacao_Autonoma.pdf)

13. **Xaud, M. F. S.; From, P. J.; Leite, A. C. (2025).**  
   *Robust Visual Servoing and CNN-Based Thermal Imaging for Sugarcane Row Following With a Skid-Steering Mobile Robot.*  
   IEEE Access, vol. 13, pp. 143166–143195.  
   * [PDF no repositório](./referencias/13_Xaud_2025_Sugarcane_Row_Following_CNN.pdf)
   * [DOI](https://doi.org/10.1109/ACCESS.2025.3598792)

### Caso Solix na Tereos

7. **Tereos (2023).**  
   *Tereos investe em robôs da Solinftec para eliminar plantas daninhas no campo.*  
   * [Fonte original](https://br.tereos.com/pt-pt/press-releases/tereos-investe-em-robos-da-solinftec-para-eliminar-plantas-daninhas-no-campo/)
   * [PDF no repositório](./referencias/07_Tereos_2023_Solix_Plantas_Daninhas.pdf)

8. **Vasconcelos, Y. (2025).**  
   *Robô elimina plantas invasoras e insetos-praga que prejudicam a lavoura.*  
   Pesquisa FAPESP, n. 347.  
   * [Fonte original](https://revistapesquisa.fapesp.br/robo-elimina-plantas-invasoras-e-insetos-praga-que-prejudicam-a-lavoura/)
   * [PDF no repositório](./referencias/08_Vasconcelos_2025_Pesquisa_FAPESP_Solix.pdf)

11. **Tereos (2025).**  
   *Relatório de Sustentabilidade 2024/2025.*  
   * [PDF no repositório](./referencias/11_Tereos_2025_Relatorio_Sustentabilidade_2024_2025.pdf)

12. **Solinftec (2024).**  
   *Solinftec anuncia os primeiros resultados obtidos com o seu robô Solix em lavouras e canaviais brasileiros.*  
   * [Fonte original](https://www.solinftec.com/pt-br/solinftec-anuncia-os-primeiros-resultados-obtidos-com-o-seu-robo-solix-em-lavouras-e-canaviais-brasileiros/)

14. **Solinftec (2026).**  
   *Solix AG Robotics.*  
   * [Fonte original](https://www.solinftec.com/en-us/solix-ag-robotics/)

### Agricultura 4.0 e adoção tecnológica

10. **Coca, E.; Santos, A. P.; Giacopini, R. (2026).**  
   *Geografias Digitais e Agricultura 4.0 na Região Geográfica Intermediária de Varginha-MG: O Fosso Digital no Campo.*  
   GEOgraphia, vol. 28, no. 60.  
   * [PDF no repositório](./referencias/10_Coca_2026_Agricultura_4_0_Fosso_Digital.pdf)
   * [DOI](https://doi.org/10.22409/GEOgraphia2026.v28i60.a66216)

### Evidências de expansão comercial

15. **Balago, R. (2024).**  
   *Fazenda em Goiás usará robôs com IA para fazer todo o combate a ervas daninhas.*  
   Exame.  
   * [Fonte original](https://exame.com/agro/fazenda-em-goias-usara-robos-com-ia-para-fazer-todo-o-combate-a-ervas-daninhas/)

16. **Fazendas Reunidas Baumgart (2024).**  
   *Relatório de Sustentabilidade 2024.*  
   * [PDF no repositório](./referencias/16_Baumgart_2024_Relatorio_Sustentabilidade.pdf)

## Organização dos arquivos

```text
Trabalho_2/
├── README.md
├── documento/
│   └── Trabalho_2_Agricultura_Inteligente_Solix_Tereos.pdf
└── referencias/
    ├── 01_Pivoto_2023_Smart_Farming_Brazil.pdf
    ├── 02_Sharma_2024_AI_IoT_Precision_Agriculture.pdf
    ├── 03_Oliveira_2019_Agricultural_Mobile_Robot_Cotton.pdf
    ├── 04_Upadhyay_2024_Robotic_Weed_Management.pdf
    ├── 05_Vijayakumar_2023_Smart_Spraying_Weed_Management.pdf
    ├── 06_Tian_2023_Integrated_Navigation_Agricultural_Robot.pdf
    ├── 07_Tereos_2023_Solix_Plantas_Daninhas.pdf
    ├── 08_Vasconcelos_2025_Pesquisa_FAPESP_Solix.pdf
    ├── 09_Martins_2021_Soybot_Navegacao_Autonoma.pdf
    ├── 10_Coca_2026_Agricultura_4_0_Fosso_Digital.pdf
    ├── 11_Tereos_2025_Relatorio_Sustentabilidade_2024_2025.pdf
    ├── 13_Xaud_2025_Sugarcane_Row_Following_CNN.pdf
    └── 16_Baumgart_2024_Relatorio_Sustentabilidade.pdf
```

## Finalidade

Os materiais desta pasta possuem finalidade **acadêmica** e documentam as fontes utilizadas na elaboração do Trabalho 2 da disciplina TP-546.
