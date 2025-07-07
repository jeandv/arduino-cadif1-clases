// CIRCUTIO TINKERCAD = https://www.tinkercad.com/things/id44sTBgTmq-desafio2arduinoivjeanrondon

#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C pantalla(0x20, 16, 2);

const int pinSensorTMP36 = A0;
float temperaturaActual = 0.0;
const int pinMotor = 2;
bool motorEncendido = false;

const float TEMP_MIN_NORMAL = 18.0;
const float TEMP_MAX_NORMAL = 21.0;

void setup()
{
  Serial.begin(9600);

  pantalla.init();
  pantalla.backlight();

  pinMode(pinMotor, OUTPUT);
  digitalWrite(pinMotor, LOW);

  pantalla.setCursor(2, 0);
  pantalla.print("Bienvenido!");
  pantalla.setCursor(6, 1);
  pantalla.print(":D");

  delay(2000);
  pantalla.clear();

  pantalla.setCursor(3, 0);
  pantalla.print("INICIANDO");
  pantalla.setCursor(2, 1);
  pantalla.print("INVERNADERO!");

  Serial.print("--- INICIANDO");
  Serial.println(" INVERNADERO ---");

  delay(3000);
  pantalla.clear();
}

void loop()
{
  temperaturaActual = leerTemperatura();

  if (temperaturaActual > TEMP_MAX_NORMAL)
  {

    controlarMotor(true);
    mensajeLCD(temperaturaActual, true);
  }
  else if (temperaturaActual < TEMP_MIN_NORMAL)
  {

    controlarMotor(false);
    mensajeLCD(temperaturaActual, false);
  }
  else
  {
    mensajeLCD(temperaturaActual, motorEncendido);
  }

  delay(1000);
}

float leerTemperatura()
{
  int valorSensor = analogRead(pinSensorTMP36);
  float voltaje = (valorSensor / 1024.0) * 5.0;
  return (voltaje - 0.5) * 100.0;
}

void controlarMotor(bool encender)
{
  if (encender)
  {
    digitalWrite(pinMotor, 1);
    motorEncendido = true;
  }
  else
  {
    digitalWrite(pinMotor, 0);
    motorEncendido = false;
  }
}

void mensajeLCD(float temp, bool motorActivo)
{
  pantalla.clear();

  if (temp > TEMP_MAX_NORMAL)
  {

    pantalla.clear();
    pantalla.setCursor(0, 0);
    pantalla.print("Temp: ");
    pantalla.print(temp);
    pantalla.print("C");
    pantalla.setCursor(0, 1);
    pantalla.print("temperatura ALTA");
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print("C");
    Serial.println(" - temperatura ALTA");
  }
  else if (temp < TEMP_MIN_NORMAL)
  {

    pantalla.clear();
    pantalla.setCursor(0, 0);
    pantalla.print("Temp: ");
    pantalla.print(temp);
    pantalla.print("C");
    pantalla.setCursor(0, 1);
    pantalla.print("temperatura BAJA");
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print("C");
    Serial.println(" - temperatura BAJA");
  }
  else
  {
    pantalla.clear();
    pantalla.setCursor(0, 0);
    pantalla.print("Temp: ");
    pantalla.print(temp);
    pantalla.print("C");
    pantalla.setCursor(0, 1);
    pantalla.print("temperatura NORMAL");
    Serial.print("Temp: ");
    Serial.print(temp);
    Serial.print("C");
    Serial.println(" - temperatura NORMAL");
  }
}