// CIRCUITO ARDUINO = https://www.tinkercad.com/things/86Z40N32fpj-desafio4arduino2jeanrondon

// REQUERIMIENTO 3, 4 y 5
const int potencioPin = A3;

const int ledPin10 = 10;
const int ledPin11 = 11;
const int ledPin12 = 12;
const int ledPin13 = 13;

void setup()
{
  Serial.begin(9600);

  // REQUERIMIENTO 3, 4 y 5
  pinMode(ledPin10, OUTPUT);
  pinMode(ledPin11, OUTPUT);
  pinMode(ledPin12, OUTPUT);
  pinMode(ledPin13, OUTPUT);

  Serial.println("-- INICIO DE PROGRAMAS --");
}

void loop()
{
  // REQUERIMIENTO 1
  for (int brillo = 0; brillo <= 255; brillo++)
  {
    analogWrite(5, brillo);
    delay(5);
  }

  // REQUERIMIENTO 2
  for (int brillo2 = 255; brillo2 >= 0; brillo2--)
  {
    analogWrite(6, brillo2);
    delay(5);
  }

  // REQUERIMIENTO 3, 4 y 5
  int potencioValor = analogRead(potencioPin);

  Serial.print("valor del Potenciometro: ");
  Serial.println(potencioValor);

  digitalWrite(ledPin10, 0);
  digitalWrite(ledPin11, 0);
  digitalWrite(ledPin12, 0);
  digitalWrite(ledPin13, 0);

  if (potencioValor > 50 && potencioValor <= 200)
  {
    digitalWrite(ledPin10, 1);
  }
  else if (potencioValor > 200 && potencioValor <= 600)
  {
    digitalWrite(ledPin10, 1);
    digitalWrite(ledPin11, 1);
  }
  else if (potencioValor > 600 && potencioValor <= 900)
  {
    digitalWrite(ledPin10, 1);
    digitalWrite(ledPin11, 1);
    digitalWrite(ledPin12, 1);
  }
  else if (potencioValor > 900)
  {
    digitalWrite(ledPin10, 1);
    digitalWrite(ledPin11, 1);
    digitalWrite(ledPin12, 1);
    digitalWrite(ledPin13, 1);
  }

  delay(10);
}