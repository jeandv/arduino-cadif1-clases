// TINKERCAD = https://www.tinkercad.com/things/khOA1F18LvR-clase4arduinoivjeanrondon

#include <Stepper.h>

Stepper PasoAPaso(2048, 8, 10, 9, 11);

int dato;
int clave1 = 0, clave2 = 2, clave3 = 3;
bool estado = true;
String clear;

void setup() {
  Serial.begin(9600);
  clear = Serial.readString();

  // PasoAPaso.setSpeed(10);
  // PasoAPaso.step(0);

  Serial.println("Inserta la clave secreta que consta con 3 digitos...");
  delay(3000);

  while (estado) {
    do {
      Serial.println("Mande el PRIMER DIGITO de la clave secreta");
      delay(1000);
    } while (Serial.available() == 0);
    clave1 = Serial.parseInt();
    clear = Serial.readString();

    do {
      Serial.println("Mande el SEGUNDO DIGITO de la clave secreta");
      delay(1000);
    } while (Serial.available() == 0);
    clave2 = Serial.parseInt();
    clear = Serial.readString();

    do {
      Serial.println("Mande el TERCER DIGITO de la clave secreta");
      delay(1000);
    } while (Serial.available() == 0);
    clave3 = Serial.parseInt();
    clear = Serial.readString();

    if ((clave1 == 3) and (clave2 == 3) and (clave3 == 3)) {
      Serial.println("CLAVE CORRECTA");
      estado = false;
      delay(3000);
    } else {
      Serial.println("CLAVE INCORRECTA");
      estado = true;
      delay(3000);
    }
  }
}

void loop() {

  // if (Serial.available()>0) {
  //   dato = Serial.parseInt();

  // switch (dato) {
  //     case 1:
  //       usarMotorPasoApaso(250, 5, 250);

  //       break;

  //     case 2:
  //       usarMotorPasoApaso(500, 10, 250);

  //       break;

  //     case 3:
  //       usarMotorPasoApaso(800, 15, 500);

  //       break;

  //     default:
  //       Serial.println("Inserta un numero del 1 al 3");

  //       break;

  // }

  // digitalWrite(9, 0);
  // digitalWrite(10, 0);
  // digitalWrite(11, 0);
  // digitalWrite(12, 0);
  // delay(5000);
}

void usarMotorPasoApaso(int step, int speed, int delayNro) {
  PasoAPaso.setSpeed(speed);
  PasoAPaso.step(step);
  delay(delayNro);
  PasoAPaso.step(-step);
  delay(delayNro);
}