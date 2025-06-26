// CIRCUITO ARDUINO = https://www.tinkercad.com/things/0tKJTxk7CrG-requerimiento5desafio3arduino1jeanrondon

const int ledPin = 6;
const int delayUsado = 400;
int brillo = 255;
int incremento = -25;

void setup()
{
  Serial.begin(9600);
  pinMode(6, OUTPUT);
}

void loop()
{
  analogWrite(ledPin, brillo);
  delay(delayUsado);

  brillo += incremento;

  if (brillo <= 0)
  {

    brillo = 0;
    incremento = 25;
    Serial.println("aumenta brillo del LED");
  }
  else if (brillo >= 255)
  {

    brillo = 255;
    incremento = -25;
    Serial.println("disminuye brillo del LED");
  }
}
