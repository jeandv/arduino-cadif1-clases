// CIRCUITO ARDUINO = https://www.tinkercad.com/things/fbpHSZ7ilC0-desafio3arduinonivel3jeanrondon

const int capacidadTanque = 6;
const int nivelMinTanque = 1;
const int nivelMaxTanque = 5;
const int pinRele = 2;
const int pinBuzzer = 3;
const int frecuenciaNivelBajo = 500;
const int frecuenciaNivelAlto = 1200;
int nivelAgua;
bool bombaEncendida = false;
unsigned long tiempoInicioBuzzer = 0;
bool buzzerActivo = false;

void setup()
{
  Serial.begin(9600);

  pinMode(pinRele, OUTPUT);
  digitalWrite(pinRele, 0);

  pinMode(pinBuzzer, OUTPUT);

  randomSeed(analogRead(A0));
}

void loop()
{

  nivelAgua = random(0, capacidadTanque + 1);

  Serial.print("Nivel actual de agua: ");
  Serial.print(nivelAgua);
  Serial.println(" litros");

  if (nivelAgua <= nivelMinTanque && !bombaEncendida)
  {

    digitalWrite(pinRele, HIGH);
    bombaEncendida = true;
    Serial.println("--- NIVEL DE AGUA BAJO | BOMBA ENCENDIDA ---");
    tone(pinBuzzer, frecuenciaNivelBajo);
    tiempoInicioBuzzer = millis();
    buzzerActivo = true;
  }
  else if (nivelAgua >= nivelMaxTanque && bombaEncendida)
  {

    digitalWrite(pinRele, LOW);
    bombaEncendida = false;
    Serial.println("--- NIVEL DE AGUA ALTO | BOMBA APAGADA ---");
    tone(pinBuzzer, frecuenciaNivelAlto);
    tiempoInicioBuzzer = millis();
    buzzerActivo = true;
  }

  if (buzzerActivo && (millis() - tiempoInicioBuzzer >= 10000))
  {
    noTone(pinBuzzer);
    buzzerActivo = false;
    Serial.println("Buzzer APAGADO");
  }

  delay(2000);
}