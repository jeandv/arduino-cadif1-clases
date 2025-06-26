// CIRCUITO ARDUINO = https://www.tinkercad.com/things/cQB3lJHU2vq-requerimiento4desafio3arduino1jeanrondon

String mensajeLuzVerde = "LUZ VERDE ENCENDIDA: El peaton SI puede cruzar con seguridad.";
String mensajeLuzAmarillo = "LUZ AMARILLA ENCENDIDA: Precaucion, el peaton puede cruzar pero debe tener cuidado.";
String mensajeLuzRojo = "LUZ ROJA ENCENDIDA: El peaton NO debe cruzar, espere por favor por su seguridad.";

void setup()
{
  Serial.begin(9600);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  Serial.println("SEMAFORO ACTIVADO");
}

void loop()
{
  digitalWrite(5, HIGH);
  Serial.println(mensajeLuzVerde);
  delay(5000);
  digitalWrite(5, LOW);

  digitalWrite(6, HIGH);
  Serial.println(mensajeLuzAmarillo);
  delay(5000);
  digitalWrite(6, LOW);

  digitalWrite(7, HIGH);
  Serial.println(mensajeLuzRojo);
  delay(5000);
  digitalWrite(7, LOW);

  delay(1000);
}