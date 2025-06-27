// CIRCUITO ARDUINO = https://www.tinkercad.com/things/hgMBak8GmLm-desafio3arduino2jeanrondon

int valorInput = 0;

int pinLED = 10;
int pinButton = 8;

void setup()
{
  Serial.begin(9600);

  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLED, OUTPUT);
}

void loop()
{

  valorInput = digitalRead(pinButton);

  if (valorInput == HIGH)
  {
    digitalWrite(pinLED, 1);
    Serial.println("La puerta esta abierta.");
  }
  else
  {
    digitalWrite(pinLED, 0);
    Serial.println("La puerta esta cerrada.");
  }

  delay(1000);
}