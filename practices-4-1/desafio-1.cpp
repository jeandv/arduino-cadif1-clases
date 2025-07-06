// CIRCUITO TINKERCAD https://www.tinkercad.com/things/hdD6PlqqJaJ-desafio1arduinoivjeanrondon

#include <LiquidCrystal.h>

LiquidCrystal pantalla(12, 11, 5, 4, 3, 2);

byte corazon[] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000};

int frecuenciaCardiaca = 0;

void setup()
{
  Serial.begin(9600);
  pantalla.begin(16, 2);

  pantalla.createChar(0, corazon);

  pantalla.setCursor(0, 0);
  pantalla.print("Frec. Cardiaca");
  pantalla.display();
}

void loop()
{
  if (Serial.available())
  {
    frecuenciaCardiaca = Serial.parseInt();
    pantalla.setCursor(0, 1);
    pantalla.print("                ");
    pantalla.setCursor(0, 1);
    pantalla.print(frecuenciaCardiaca);
    pantalla.write(byte(0));
  }

  if (frecuenciaCardiaca > 100)
    parpadearPantalla();
  else
    pantalla.display();
}

void parpadearPantalla()
{
  pantalla.noDisplay();
  delay(250);
  pantalla.display();
  delay(250);
}