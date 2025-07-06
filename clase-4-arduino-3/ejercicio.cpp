// CIRCUITO ARDUINO CLASE 4 = https://www.tinkercad.com/things/1Wig3Uw5WTA-clase4arduinonivel3

// void setup()
//{
//   pinMode(3, OUTPUT);
//   pinMode(4, OUTPUT);
//   pinMode(5, OUTPUT);
//   pinMode(6, OUTPUT);
//   pinMode(7, OUTPUT);
//   pinMode(8, OUTPUT);
//   pinMode(9, OUTPUT);
// }

// void apagar() {
//   digitalWrite(3, 0); //a
//   digitalWrite(4, 0); //b
//   digitalWrite(5, 0); //c
//   digitalWrite(6, 0); //d
//   digitalWrite(7, 0); //e
//   digitalWrite(8, 0); //f
//   digitalWrite(9, 0); //g
// }

// void uno() {
//   digitalWrite(3, 0); //a
//   digitalWrite(4, 1); //b
//   digitalWrite(5, 1); //c
//   digitalWrite(6, 0); //d
//   digitalWrite(7, 0); //e
//   digitalWrite(8, 0); //f
//   digitalWrite(9, 0); //g
// }

// void loop()
//{
//  uno();
// }

const int SEG_A = 3;
const int SEG_B = 4;
const int SEG_C = 5;
const int SEG_D = 6;
const int SEG_E = 7;
const int SEG_F = 8;
const int SEG_G = 9;

const int segmentPins[] = {SEG_A, SEG_B, SEG_C, SEG_D, SEG_E, SEG_F, SEG_G};
const int NUM_SEGMENTS = sizeof(segmentPins) / sizeof(segmentPins[0]);

const byte digitPatterns[][NUM_SEGMENTS] = {
    {1, 1, 1, 1, 1, 1, 0},
    {0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 1},
    {1, 1, 1, 1, 0, 0, 1},
    {0, 1, 1, 0, 0, 1, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {1, 0, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}};

void setup()
{
  for (int i = 0; i < NUM_SEGMENTS; i++)
  {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void clearDisplay()
{
  for (int i = 0; i < NUM_SEGMENTS; i++)
  {
    digitalWrite(segmentPins[i], LOW);
  }
}

void displayDigit(int digit)
{
  if (digit >= 0 && digit <= 9)
  {
    clearDisplay();
    for (int i = 0; i < NUM_SEGMENTS; i++)
    {
      digitalWrite(segmentPins[i], digitPatterns[digit][i]);
    }
  }
  else
  {
    clearDisplay();
  }
}

void loop()
{
  //  for (int i = 0; i <= 9; i++) {
  //  displayDigit(i);
  // delay(1000);
  //}

  displayDigit(1);
}

#include <TM1637TinyDisplay.h>

// // const int pirPin = 2;
// // const int ledPin = 5;
// // int val = 0;

// // void setup() {
// //   Serial.begin(9600);
// //   pinMode(ledPin, OUTPUT);
// //   pinMode(pirPin, INPUT);
// //   Serial.println("PROGRAMA INICIADO: ");
// // }

// // void loop() {
// //   val = digitalRead(pirPin);
// //   if (val == HIGH) {
// //     digitalWrite(ledPin, 1);
// //     Serial.println("MOVIMIENTO DETECTADO");
// //   } else {
// //     digitalWrite(ledPin, 0);
// //   }
// // }

// // double duracion;
// // double distancia;
// // int echo = 8;
// // int trig = 9;
// // const int ledPin = 2;

// // void setup() {
// //   Serial.begin(9600);
// //   pinMode(trig, OUTPUT);
// //   pinMode(echo, INPUT);
// //   pinMode(ledPin, OUTPUT);
// // }

// // void loop() {
// //   digitalWrite(trig, 0);
// //   delayMicroseconds(4);
// //   digitalWrite(trig, 1);
// //   delayMicroseconds(10);
// //   digitalWrite(trig, 0);

// //   duracion = pulseIn(echo, 1);

// //   distancia = duracion/58.4;

// //   Serial.print("Distancia: ");
// //   Serial.print(distancia);
// //   Serial.println(" cm");

// //   if (distancia > 5) {
// //     digitalWrite(ledPin, 1);
// //     delay(1000 * (distancia * 2));
// //     digitalWrite(ledPin, 0);
// //   } else {
// //     digitalWrite(ledPin, 0);
// //   }

// //   delay(100);

// // }

// byte CLK =2, DIO =3;
// int var = 0;

// TM1637TinyDisplay tiempo (CLK, DIO);

// void setup() {
//   Serial.begin(9600);
//   tiempo.setBrightnes(4);
// }

// void loop() {
//   tiempo.showNumber(var, false, 3);
//   delay(500);
//   tiempo.showString("jean");
//   delay(500);
// tiempo.clear();
//   delay(500);
// var++

// if (var == 22) {
// var =0;
// }
// }