// CIRCUITO ARDUINO = https://www.tinkercad.com/things/krhePXZH3W7-desafio2arduino2jeanrondon

int numeroInsertado;

void setup()
{
  Serial.begin(9600);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  Serial.println("--- PROGRAMA INICIADO ---");
}

void loop()
{
  if (Serial.available() > 0)
  {
    numeroInsertado = Serial.read() - '0'; // uso el -'0' para no usar el codigo ASCI y usar los numeros como se insertan.
    Serial.print("El numero insertado es: ");

    if (numeroInsertado == 0)
    {
      Serial.println("El Estado del nivel del tanque es BAJO");

      digitalWrite(10, 1);
      digitalWrite(11, 0);
      digitalWrite(12, 0);

      Serial.println("---------------------------------");
    }

    if (numeroInsertado == 1)
    {
      Serial.println("El Estado del nivel del tanque es INTERMEDIO");

      digitalWrite(10, 1);
      digitalWrite(11, 1);
      digitalWrite(12, 0);

      Serial.println("----------------------------------");
    }

    if (numeroInsertado == 2)
    {
      Serial.println("El Estado del nivel del tanque es ALTO");

      digitalWrite(10, 1);
      digitalWrite(11, 1);
      digitalWrite(12, 1);

      Serial.println("------------------------------------");
    }
  }
}

// int numeroInsertado = -1;
// bool entradaValida;

// void setup()
//{
//   Serial.begin(9600);
//
//   pinMode(10, OUTPUT);
//   pinMode(11, OUTPUT);
//   pinMode(12, OUTPUT);
//
//   Serial.println("--- PROGRAMA INICIADO ---");
// }
//
// void loop()
//{
//   if (Serial.available() > 0) {
//	numeroInsertado = Serial.read() - '0';
//
//	Serial.print("El numero insertado es: ");
//	Serial.println(numeroInsertado);
//
//     entradaValida = false;
//
//     if (numeroInsertado >= 0 && numeroInsertado <= 2) {
//	  entradaValida = true;
//
//       if (numeroInsertado == 0) {
//         Serial.println("El Estado del nivel del tanque es BAJO");
//
//         digitalWrite(10, 1);
//         digitalWrite(11, 0);
//         digitalWrite(12, 0);
//
//         Serial.println("---------------------------------");
//       }
//
//       if (numeroInsertado == 1) {
//         Serial.println("El Estado del nivel del tanque es INTERMEDIO");
//
//         digitalWrite(10, 1);
//         digitalWrite(11, 1);
//         digitalWrite(12, 0);
//
//         Serial.println("----------------------------------");
//       }
//
//       if (numeroInsertado == 2) {
//         Serial.println("El Estado del nivel del tanque es ALTO");
//
//         digitalWrite(10, 1);
//         digitalWrite(11, 1);
//         digitalWrite(12, 1);
//
//         Serial.println("------------------------------------");
//       }
//
//     }
//
//     if (!entradaValida) {
//      Serial.println("No se encendera ningun LED");
//	 Serial.println("El numero insertado es incorrecto, solo debes insertar los numeros 0, 1 o 2");
//	 Serial.println("----------------------------------");
//     }
//
//   }
// }