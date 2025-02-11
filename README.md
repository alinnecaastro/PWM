# Controle de servomotor por PWM

## Estrutura do Projeto  
- **build/** → Diretório de compilação gerado pelo CMake. 
- **codigo_led.txt** → Codigos para observa o comportamento da iluminação do referido LED  
- **diagram.json** → Simulação do Wokwi 
- **CMakeLists.txt** → Configuração do CMake para compilação.  
- **PWM.c** → Código principal do projeto.   
- **pico_sdk_import.cmake** → Importação do SDK do Raspberry Pi Pico.  
- **README.md** → Documentação do projeto.  
- **wokwi.toml** → Arquivos de configuração para simulação no Wokwi.  



## Descrição Geral

Este projeto utiliza o Pico SDK para simular o controle do ângulo de um servomotor. A simulação será realizada com o motor micro servo padrão, presente no simulador de eletrônica online Wokwi, ajustando a posição do motor com base na variação do ciclo de trabalho (Duty Cycle) do sinal PWM. O objetivo é controlar com precisão o movimento do servomotor, permitindo que ele se posicione de acordo com os diferentes valores de ciclo de trabalho, simulando a movimentação do braço do servo entre 0° e 180°.
 

## Video do funcionamento do projeto usando o led RGB e GPIO 12 
https://drive.google.com/file/d/1hIG8jx_iI1Uijh_XgKumP72KiHPIL_Fe/view?usp=sharingg

## Video do funcionamento do projeto usando a mistura do RGB GPIO 11 e 13
https://drive.google.com/file/d/1hFvHJdBVumI_FLqVhMKsY6Kh4CNnfYm6/view?usp=drive_link

## Video do funcionamento no simulador dentro do vscode com GPIO 12 
https://drive.google.com/file/d/1xbVxYecFbzsi63KqMtRlpHYz-4fz1_2y/view?usp=sharing

## Video do funcionamento no simulador dentro do vscode com GPIO 11 e 13
https://drive.google.com/file/d/13pP_0ThIzlzZgzseRZ6ZozHRleIOc3X8/view?usp=sharing

## Componentes Utilizados:
- Microcontrolador Raspberry Pi Pico W
- LED RGB: Utilizado para experimentos adicionais
- Servomotor: Micro Servo Padrão (simulado no Wokwi)


## Fluxograma Simplificado
1. Configura PWM
2. Ajustar o Ciclo de Trabaljo (Duty Cycle)
3. Posicionar o Servomotor
4. Aguardar 5 segundos
5. Movimentação suave 

## Funcionalidades do Projeto
1. Defini frequência de PWM na GPIO 22 para aproximadamente 50HZ
2. Ajusta o ciclo de trabalho para 2400us(180°);
3. Ajusta o ciclo de trabalho para 1470us(90°);
4. Ajusta o ciclo de trabalho para 400us (0°);
5. Movimenta periodicamente entre 0° a 180°;
6. Experiemnto com o LED RGB - GPIO 12


## Requisitos do Projeto
- Configuração de Frequência de PWM;
- Ajuste do Ciclo Ativo (Duty Cycle) do PWM;
- Movimentação Periódia do Servomotor entre 0° a 180°;
- Experiemento com o LED RGB - GPIO 12

## Configuração do Ambiente

1. Instalação do SDK do Raspberry Pi Pico
Para configurar o ambiente de desenvolvimento, siga as instruções de instalação do SDK do Raspberry Pi Pico, incluindo a configuração do Visual Studio Code com as extensões apropriadas para compilar e carregar o código no microcontrolador.

2. Clone o Repositório
Clone o repositório com o código-fonte do projeto:
git clone: https://github.com/alinnecaastro/Semaforo.git

3. Compilação do Projeto
Para compilar o projeto, abra o Visual Studio Code e siga os seguintes passos:

- Clean CMake – Para garantir que o projeto seja compilado a partir do zero.
- Compile Project – Para compilar o código-fonte e gerar o binário.
- Run Project [USB] – Para carregar o código no Raspberry Pi Pico W via USB.

4. Carregue o Firmware no Raspberry Pi Pico W
Conecte o Raspberry Pi Pico W ao computador e faça o upload do firmware gerado para a placa.


## Funcionamento do Código

1. Configuração do PWM
 - A GPIO 22 é configurada para gerar um sina PWM com frequência 50HZ, o que significa que o periodo será de 20ms.
 
2. Definição do Ciclo de Trabalho (Duty cycle)
 - Ele determina a posição do servomotor,
    - 500µs (0 graus)
    - 1470µs (90 graus)
    - 2400µs (180 graus) 

3. Movimentação Suave do Servomotor
 - O código realiza uma movimentação suave do servomotor entre os ângulos de 0 a 180 graus e de 180 a 0 graus. A movimentação suave é implementada através de um incremento gradual no pulse width (largura do pulso) de ±5µs a cada iteração, e um atraso de 10ms entre os ajustes, permitindo que o servomotor se mova de forma contínua e gradual.

## Conclusão
Esse código controla o servomotor de forma eficiente e suave, utilizando PWM para ajustar a posição do braço do servomotor. A movimentação entre os ângulos de 0 e 180 graus é realizada de forma gradual e contínua, proporcionando um controle preciso e suave. O código pode ser facilmente adaptado para outros servomotores e diferentes configurações de hardware, mantendo o controle de posição com base no PWM.