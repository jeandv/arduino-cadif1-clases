// CIRCUITO ARDUINO = https://www.tinkercad.com/things/6uVJNSlObTz-desafio4arduino1jeanrondon

int voltaje = 110;
int corriente;
int potencia;

// Requerimiento 3, 4 y 5
int ledPin = 13;
int valorPWM;

void setup()
{
  Serial.begin(9600);
  // Requerimiento 3, 4 y 5
  randomSeed(analogRead(0));
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  // Requerimiento 1 y 2
  corriente = random(1, 11);
  potencia = voltaje * corriente;
  Serial.print("La potencia del artefacto cuando es alimentado por 110 Voltios y por el circula una corriente de: ");
  Serial.print(corriente);
  Serial.print(" amperios y disipa una potencia de: ");
  Serial.print(potencia);
  Serial.println(" vatios");

  // Requerimiento 3, 4 y 5
  valorPWM = random(256);
  analogWrite(ledPin, valorPWM);

  delay(1000);
}