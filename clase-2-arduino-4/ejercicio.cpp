#define salida 3

void setup()
{
  Serial.begin(9600);
  pinMode(salida, OUTPUT);
}

void loop()
{
  Serial.println("El motor esta prendido");
  digitalWrite(salida, 1);
  delay(2000);
  Serial.println("El motor esta apagado");
  digitalWrite(salida, 0);
  delay(2000);

  // analogWrite(salida, 30); //para usar de manera gradual
}

#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;

int motorBase = 4;
int motorBase3 = 5;

int motorBase2 = 6;
int pulsoMinimo = 500;
int pulsoMaximo = 2400;

void setup()
{
  Serial.begin(9600);
  motor1.attach(motorBase, pulsoMinimo, pulsoMaximo);
  motor1.write(0);

  motor2.attach(motorBase2, pulsoMinimo, pulsoMaximo);
  motor2.write(0);

  motor3.attach(motorBase3, pulsoMinimo, pulsoMaximo);
  motor3.write(0);
  delay(100);
}

void loop()
{
  for (byte j = 5; j <= 135; j++)
  {
    motor1.write(j);
    motor2.write(j);
    motor3.write(j);

    delay(50);
    Serial.println(j);
    j++;
  }

  for (byte i = 135; i >= 5; i--)
  {
    motor1.write(i);
    motor2.write(i);
    motor3.write(i);

    delay(50);
    Serial.println(i);
    i--;
  }
}

// #include <LiquidCrystal.h>

// #include <Wire.h>

// #define salida 3

// int luz, salidaPWM;

// LiquidCrystal_I2C pantalla(0x27,16,2);

// void setup() {
//    Serial.begin(9600);
//    pinMode(salida, OUTPUT);
//    pinMode(A0, INPUT);

//    Wire.begin();
//    pantalla.begin(16,2);
//    pantalla.clear();
//    pantalla.backlight();
//    //pantalla.noBacklight();
//    pantalla.setCursor(0,0);
//    pantalla.print("Holaa a todos");
//    pantalla.setCursor(0,1);
//    pantalla.print("bienvenidos");
//    delay(1500);
// }

// void loop() {

//   Serial.println("El motor esta prendido");
//   digitalWrite(salida, 1);
//   delay(2000);
//   Serial.println("El motor esta apagado");
//   digitalWrite(salida, 0);
//   delay(2000);
//}
