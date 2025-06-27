// CIRCUITO ARDUINO = https://www.tinkercad.com/things/6sHGmH4CWDp-desafio2arduinonivel3jeanrondon

const int sensorPin = A0;
const int rele1Pin = 2;
const int rele2Pin = 3;
const int rele3Pin = 4;
const int rele4Pin = 5;
float temperaturaC;

void setup()
{
  Serial.begin(9600);
  pinMode(rele1Pin, OUTPUT);
  pinMode(rele2Pin, OUTPUT);
  pinMode(rele3Pin, OUTPUT);
  pinMode(rele4Pin, OUTPUT);
  digitalWrite(rele1Pin, 0);
  digitalWrite(rele2Pin, 0);
  digitalWrite(rele3Pin, 0);
  digitalWrite(rele4Pin, 0);
}

float leerTemperaturaTMP36()
{
  int valorSensor = analogRead(sensorPin);
  float voltaje = (valorSensor / 1024.0) * 5.0;
  return (voltaje - 0.5) * 100.0;
}

void apagarReles()
{
  digitalWrite(rele1Pin, 0);
  digitalWrite(rele2Pin, 0);
  digitalWrite(rele3Pin, 0);
  digitalWrite(rele4Pin, 0);
}

void controlarReles(float temp)
{
  apagarReles();

  if (temp >= 10.0 && temp <= 15.0)
  {
    digitalWrite(rele1Pin, 1);
    Serial.println("Rango: 10C - 15C | Rele 1 Activo - LED VERDE");
  }
  else if (temp >= 16.0 && temp <= 18.0)
  {
    digitalWrite(rele2Pin, 1);
    Serial.println("Rango: 16C - 18C | Rele 2 Activo - LED ROJO");
  }
  else if (temp >= 23.0 && temp <= 26.0)
  {
    digitalWrite(rele3Pin, 1);
    Serial.println("Rango: 23C - 26C | Rele 3 Activo - LED AZUL");
  }
  else if (temp > 27.0)
  {
    digitalWrite(rele4Pin, 1);
    Serial.println("Rango: > 27C | Rele 4 Activo - LED AMARILLO");
  }
  else
  {
    Serial.println("Temperatura fuera de los rangos");
  }
}

void loop()
{
  Serial.print("Temperatura Actual: ");
  Serial.print(leerTemperaturaTMP36());
  Serial.println(" C");

  controlarReles(leerTemperaturaTMP36());

  delay(1000);
}