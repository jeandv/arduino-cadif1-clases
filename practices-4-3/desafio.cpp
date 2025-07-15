// CIRCUITO TINKERCAD = https://www.tinkercad.com/things/7EQEcnL5lwk-desafio3arduinoivjeanrondon

#include <LiquidCrystal_I2C.h>
#include <Servo.h>

const int pinSensorTMP36 = A0;
Servo persiana1;
Servo persiana2;

LiquidCrystal_I2C pantalla(0x20,16,2);

int posicionPersianas = -1;

void setup() {
  Serial.begin(9600);

  persiana1.attach(2);
  persiana2.attach(3);

  pantalla.init();
  pantalla.backlight();
  
  pantalla.setCursor(2, 0);
  pantalla.print("Bienvenido!");
  pantalla.setCursor(6, 1);
  pantalla.print(":D");

  delay(2000);
  pantalla.clear();

  pantalla.setCursor(3, 0);
  pantalla.print("INICIANDO");

  Serial.println("--- INICIANDO ---");
  
  delay(3000);
  pantalla.clear();
}

void loop() {
  float temperaturaActual = leerTemperatura();

  controlarPersianas(temperaturaActual);
  mostrarLCD(temperaturaActual, posicionPersianas);

  delay(1000);
}

float leerTemperatura() {
  int valorSensor = analogRead(pinSensorTMP36);
  float voltaje = (valorSensor / 1024.0) * 5.0;
  return (voltaje - 0.5) * 100.0;
}

void controlarPersianas(float temperatura) {
  int nuevaPosicion = posicionPersianas; 
  
  if (temperatura < 10.0) {
    nuevaPosicion = 0;
  } else if (temperatura >= 11.0 && temperatura <= 15.0) {
    nuevaPosicion = 30;
  } else if (temperatura >= 16.0 && temperatura <= 20.0) {
    nuevaPosicion = 45;
  } else if (temperatura > 21.0) {
    nuevaPosicion = 90;
  }

  if (nuevaPosicion != posicionPersianas) {
    persiana1.write(nuevaPosicion);
    persiana2.write(nuevaPosicion);
    posicionPersianas = nuevaPosicion;
  }
}

void mostrarLCD(float temperatura, int posicion) {
  pantalla.clear();

  pantalla.setCursor(0, 0);
  pantalla.print("T:");
  pantalla.print(temperatura, 1);
  pantalla.print("C ");

  Serial.print("Temperatura: ");
  Serial.print(temperatura, 1);
  Serial.println("C ");

  pantalla.print("Persiana");
  Serial.print("Persiana ");
  
  pantalla.setCursor(0, 1);
  if (posicion == 0) {
    pantalla.print("Cerrada ");
    pantalla.print(posicion);
	pantalla.print("GRD");

    Serial.print("Cerrada ");
    Serial.print(posicion);
	Serial.println("Grados - HAY FRIO");
	Serial.println("----------------");
  } else {
    pantalla.print("Abierta en ");
    pantalla.print(posicion);
	pantalla.print("GRD");

    Serial.print("Abierta en ");
    Serial.print(posicion);
	Serial.println(" Grados");
	Serial.println("----------------");

  }
}