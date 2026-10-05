// EX 1 
// CRIE UM PROGRAMA QUE PISQUE 2 LEDS DE FORMA ALTERNADA 
// EX 2 
// CRIE UM PROGRAMA QUE PISQUE 2 LED
// LED 1 DEVE PISCAR A CADA 500 MS 
// LED 2 DEVE PISCAR A CADA 2S
// EX 3 
// CRIE UM PROGRAMA QUE MOSTRA UMA MENSAGEM NO SERIAL A CADA 2S
// EX 4 
// CRIE UM PROGRAMA QUE AO PRESSIONAR UM BOTAO UM ACENDA E APAGUE AUTOMATICAMENTE APOS 3S 
// EX 5
// CRIE UM SEMAFORO 



#include <Arduino.h>
#include <Bounce2.h>
// #define pinLed 2

// bool estadoLed = 0;
// unsigned long tempoAnterior = 0;
// unsigned long intervalo = 500;

//ex1
// #define pinLed 2
// #define pinLed2 19
// bool estadoLed1 = 1;
// bool estadoLed2 = 0;
// unsigned long tempoAnterior = 0;
// unsigned long intervalo = 500
// ===========================
// #define pinLed 2
// #define pinLed2 19
// bool estadoLed1 = 1;
// bool estadoLed2 = 0;
//ex2
// unsigned long tempoAnterior = 0;
// unsigned long intervalo = 500;
// unsigned long tempoAnterior2 = 0;
// unsigned long intervalo2 = 2000;
//ex3
// bool estadoLed = 1;
// unsigned long tempoAnterior = 0;
// unsigned long intervalo = 2000;
//ex4
// bool ledAcesso = false;
// unsigned long tempoAnterior = 0;
// unsigned long intervalo = 3000;
// #define pinBotao 32
// #define pinLed 2
// Bounce bounce = Bounce();
//ex5
#define pinVermelho 15
#define pinAmarelo 4
#define pinVerde 2
#define TEMPO_VERDE 4000    
#define TEMPO_AMARELO 2000  
#define TEMPO_VERMELHO 6000  
int estadoSemaforo = 0; 
unsigned long tempoAnterior = 0;
void setup() {
  //ex1
  //  pinMode(pinLed, OUTPUT);
  // Serial.begin(115200);
  // Serial.begin(115200);
  // pinMode(pinLed, OUTPUT);
  // pinMode(pinLed2, OUTPUT);
  // Serial.begin(115200);
  // pinMode(pinLed, OUTPUT);
  // pinMode(pinLed2, OUTPUT);
  //ex 3
  // Serial.begin(115200);
  //ex 4
  // Serial.begin(115200);
  // pinMode(pinLed, OUTPUT);
  // digitalWrite(pinLed, LOW);
  // bounce.attach(pinBotao, INPUT_PULLUP);
  //ex5
  Serial.begin(115200);
    pinMode(pinVerde, OUTPUT);
      pinMode(pinAmarelo, OUTPUT);
        pinMode(pinVermelho, OUTPUT);
}

void loop() {
//ex1
  // unsigned long tempoAtual = millis();
  // if (tempoAtual - tempoAnterior >= intervalo)
  // {
  // estadoLed1 = !estadoLed1;
  // estadoLed2 = !estadoLed2;
  // tempoAnterior = tempoAtual; 
  // } 
  // digitalWrite(pinLed, estadoLed1);
  // digitalWrite(pinLed, estadoLed2);
  // =====================================================================
  // ex2
  //   unsigned long tempoAtual = millis();
  // if (tempoAtual - tempoAnterior >= intervalo)
  // {
  // estadoLed1 = !estadoLed1;
  // tempoAnterior = tempoAtual; 
  // } 
  // digitalWrite(pinLed, estadoLed1);

  //   unsigned long tempoAtual2 = millis();

  // if (tempoAtual2 - tempoAnterior2 >= intervalo2)
  // {
  // estadoLed2 = !estadoLed2;
  // tempoAnterior2 = tempoAtual2; 
  // } 
  // digitalWrite(pinLed2, estadoLed2);
  // =========================================================================
  // ex3
  //      unsigned long tempoAtual = millis();
  // if (tempoAtual - tempoAnterior >= intervalo)
  // {
  // estadoLed = !estadoLed;
  // tempoAnterior = tempoAtual; 
  // Serial.println("Passou 2 Segundos");
  // } 
// ======================================================================
    // ex4
//     bounce.update();

//     unsigned long tempoAtual = millis();

//     if (bounce.fell())
//     {
//       ledAcesso = true;
//       tempoAnterior = millis();
//       digitalWrite(pinLed, HIGH);
//     }
//     if (ledAcesso)
//     {
//       if (tempoAtual - tempoAnterior >= intervalo){
//     ledAcesso = false;
//     digitalWrite(pinLed, LOW);
//     }
// =========================================================
//ex5
unsigned long tempoAtual = millis();

    if(estadoSemaforo == 0){
  digitalWrite(pinVerde, HIGH);
  digitalWrite(pinAmarelo, LOW);
  digitalWrite(pinVermelho, LOW);

  if (tempoAtual - tempoAnterior >= TEMPO_VERDE){
    estadoSemaforo = 1;
    tempoAnterior = tempoAtual;
    }
  }
  else if (estadoSemaforo == 1){
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarelo, HIGH);
  digitalWrite(pinVermelho, LOW);
  
  if(tempoAtual - tempoAnterior>= TEMPO_AMARELO){
  estadoSemaforo = 2;
  tempoAnterior = tempoAtual;
  }
}
  else if (estadoSemaforo == 2){
  digitalWrite(pinVerde, LOW);
  digitalWrite(pinAmarelo, LOW);
  digitalWrite(pinVermelho, HIGH);
  
  if(tempoAtual - tempoAnterior>= TEMPO_VERMELHO){
  estadoSemaforo = 0;
  tempoAnterior = tempoAtual;
  }
}
// }
}
