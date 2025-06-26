// TINKERCAD ARDUINO = https://www.tinkercad.com/things/9WcudXT0jED-desafio1arduino2jeanrondon

double R, T, logaritmoNaturalRes, unoSobreTemperaturaKelvin, porcentaje = 0.25, totalPorcentaje;

const double Ro = 10000.0;
const double To = 298.0;
const double B = 3977.0;

int contador;

void setup()
{
  Serial.begin(9600);

  randomSeed(analogRead(0));
}

void loop()
{
  contador++;

  Serial.print("--- SENSOR NTC | Registro #");
  Serial.print(contador);
  Serial.println(" ---");

  R = random(5000, 15001);
  Serial.print("Resistencia: ");
  Serial.print(R);
  Serial.println(" Ohmios");

  logaritmoNaturalRes = log(R / Ro);
  unoSobreTemperaturaKelvin = (1 / To) + (1 / B) * logaritmoNaturalRes;
  T = 1 / unoSobreTemperaturaKelvin;

  Serial.print("Temperatura: ");
  Serial.print(T);
  Serial.println(" K (Grados kelvin)");

  totalPorcentaje = T * porcentaje;
  Serial.print("25% de la Temperatura: ");
  Serial.print(totalPorcentaje);
  Serial.println(" K (Grados kelvin)");

  Serial.println("----------------");
  delay(10000);
}