// CIRCUITO ARDUINO = https://www.tinkercad.com/things/cL5hO8UC5vZ-desafio4arduinonivel3jeanrondon

const int aPin = 2;
const int bPin = 3;
const int cPin = 4;
const int dPin = 5;
const int ePin = 6;
const int fPin = 7;
const int gPin = 8;

const int botonIncrementoPin = 9;
int conteoCarros = 0;
int estadoBotonAnterior = LOW;
const int MAX_CARROS = 9;

void setup()
{
  Serial.begin(9600);
  Serial.println("--- INICIO DE PROGRAMA ---");
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);

  pinMode(botonIncrementoPin, INPUT);

  mostrarConteo(conteoCarros);
}

void loop()
{
  int estadoBotonActual = digitalRead(botonIncrementoPin);

  if (estadoBotonActual == HIGH && estadoBotonAnterior == LOW)
  {
    delay(50);
    estadoBotonActual = digitalRead(botonIncrementoPin);

    if (estadoBotonActual == HIGH)
    {

      if (conteoCarros < MAX_CARROS)
      {
        conteoCarros++;
        mostrarConteo(conteoCarros);
      }
      else
      {
        Serial.println("ESTACIONAMIENTO LLENO");
        mostrarConteo(MAX_CARROS);
      }
    }
  }

  estadoBotonAnterior = estadoBotonActual;

  delay(10);
}

void apagarTodosLosSegmentos()
{
  digitalWrite(aPin, 1);
  digitalWrite(bPin, 1);
  digitalWrite(cPin, 1);
  digitalWrite(dPin, 1);
  digitalWrite(ePin, 1);
  digitalWrite(fPin, 1);
  digitalWrite(gPin, 1);
}

void mostrarNumero0()
{
  digitalWrite(aPin, 0);
  digitalWrite(bPin, 0);
  digitalWrite(cPin, 0);
  digitalWrite(dPin, 0);
  digitalWrite(ePin, 0);
  digitalWrite(fPin, 0);
  digitalWrite(gPin, 1);
}

void mostrarNumero1()
{
  digitalWrite(aPin, 1);
  digitalWrite(bPin, 0);
  digitalWrite(cPin, 0);
  digitalWrite(dPin, 1);
  digitalWrite(ePin, 1);
  digitalWrite(fPin, 1);
  digitalWrite(gPin, 1);
}

void mostrarNumero2()
{
  digitalWrite(aPin, 0);
  digitalWrite(bPin, 0);
  digitalWrite(cPin, 1);
  digitalWrite(dPin, 0);
  digitalWrite(ePin, 0);
  digitalWrite(fPin, 1);
  digitalWrite(gPin, 0);
}

void mostrarNumero3()
{
  digitalWrite(aPin, 0);
  digitalWrite(bPin, 0);
  digitalWrite(cPin, 0);
  digitalWrite(dPin, 0);
  digitalWrite(ePin, 1);
  digitalWrite(fPin, 1);
  digitalWrite(gPin, 0);
}

void mostrarNumero4()
{
  digitalWrite(aPin, 1);
  digitalWrite(bPin, 0);
  digitalWrite(cPin, 0);
  digitalWrite(dPin, 1);
  digitalWrite(ePin, 1);
  digitalWrite(fPin, 0);
  digitalWrite(gPin, 0);
}

void mostrarNumero5()
{
  digitalWrite(aPin, 0);
  digitalWrite(bPin, 1);
  digitalWrite(cPin, 0);
  digitalWrite(dPin, 0);
  digitalWrite(ePin, 1);
  digitalWrite(fPin, 0);
  digitalWrite(gPin, 0);
}

void mostrarNumero6()
{
  digitalWrite(aPin, 0);
  digitalWrite(bPin, 1);
  digitalWrite(cPin, 0);
  digitalWrite(dPin, 0);
  digitalWrite(ePin, 0);
  digitalWrite(fPin, 0);
  digitalWrite(gPin, 0);
}

void mostrarNumero7()
{
  digitalWrite(aPin, 1);
  digitalWrite(bPin, 1);
  digitalWrite(cPin, 1);
  digitalWrite(dPin, 0);
  digitalWrite(ePin, 0);
  digitalWrite(fPin, 0);
  digitalWrite(gPin, 0);
}

void mostrarNumero8()
{
  digitalWrite(aPin, 0);
  digitalWrite(bPin, 0);
  digitalWrite(cPin, 0);
  digitalWrite(dPin, 0);
  digitalWrite(ePin, 0);
  digitalWrite(fPin, 0);
  digitalWrite(gPin, 0);
}

void mostrarNumero9()
{
  digitalWrite(aPin, 0);
  digitalWrite(bPin, 0);
  digitalWrite(cPin, 0);
  digitalWrite(dPin, 0);
  digitalWrite(ePin, 1);
  digitalWrite(fPin, 0);
  digitalWrite(gPin, 0);
}

void mostrarConteo(int numero)
{
  apagarTodosLosSegmentos();

  if (numero == 0)
  {
    mostrarNumero0();
  }
  else if (numero == 1)
  {
    mostrarNumero1();
  }
  else if (numero == 2)
  {
    mostrarNumero2();
  }
  else if (numero == 3)
  {
    mostrarNumero3();
  }
  else if (numero == 4)
  {
    mostrarNumero4();
  }
  else if (numero == 5)
  {
    mostrarNumero5();
  }
  else if (numero == 6)
  {
    mostrarNumero6();
  }
  else if (numero == 7)
  {
    mostrarNumero7();
  }
  else if (numero == 8)
  {
    mostrarNumero8();
  }
  else if (numero == 9)
  {
    mostrarNumero9();
  }

  Serial.print("Carros en el estacionamiento: ");
  Serial.println(numero);
}