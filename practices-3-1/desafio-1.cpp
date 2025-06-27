//  CIRCUITO ARDUINO = https://www.tinkercad.com/things/66B3d3MxwVa-desafio1arduinonivel3jeanrondon

const int sensorHumedadPin = A0;
const int relePin = 2;
const int minHumedad = 250;
const int maxHumedad = 800;
int valorSensorHumedad = 0;
bool bombaEncendida = false;

void setup()
{
  Serial.begin(9600);
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, 0);
}

void loop()
{
  valorSensorHumedad = analogRead(sensorHumedadPin);

  Serial.print("Humedad del suelo: ");
  Serial.println(valorSensorHumedad);

  if (valorSensorHumedad < minHumedad)
  {
    if (!bombaEncendida)
    {
      digitalWrite(relePin, 1);
      bombaEncendida = true;
      Serial.println("humedad baja encendiendo la bomba.");
    }
  }
  else if (valorSensorHumedad > maxHumedad)
  {
    if (bombaEncendida)
    {
      digitalWrite(relePin, 0);
      bombaEncendida = false;
      Serial.println("humedad alta apagando la bomba.");
    }
  }
  delay(1000);
}