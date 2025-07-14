// #include <Servo.h>

// Servo motor1;
// Servo motor2;
// Servo motor3;
// Servo motor4;


// int motorBase = 4;
// int motorBase2 = 5;
// int motorBase3 = 6;
// int motorBase4 = 7;

// int pulsoMinimo = 500;
// int pulsoMaximo = 2400;

// int pote, grados;

int pin1 = 2;
int pin2 = 3;
int pin3 = 4;
int pin4 = 5;

int demora = 20;

void setup() {
  Serial.begin(9600);

  // motor paso a paso
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);

  // motor1.attach(motorBase, pulsoMinimo, pulsoMaximo);

  // motor2.attach(motorBase2, pulsoMinimo, pulsoMaximo);

  // motor3.attach(motorBase3, pulsoMinimo, pulsoMaximo);

  // motor4.attach(motorBase4, pulsoMinimo, pulsoMaximo);

  //delay(50);
}

void loop() {

  if(Serial.available()) {

    int grados = Serial.parseInt();
    int pasos = map(grados, 0, 512, 0, 360);

    for(int i = 0; i<=pasos; i++) {

      digitalWrite(pin4, 1);
      digitalWrite(pin3, 1);
      digitalWrite(pin2, 0);
      digitalWrite(pin1, 0);

      delay(demora);

      digitalWrite(pin4, 0);
      digitalWrite(pin3, 1);
      digitalWrite(pin2, 1);
      digitalWrite(pin1, 0);

      delay(demora);

      digitalWrite(pin4, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin2, 1);
      digitalWrite(pin1, 1);

      delay(demora);

      digitalWrite(pin4, 1);
      digitalWrite(pin3, 0);
      digitalWrite(pin2, 0);
      digitalWrite(pin1, 1);

      delay(demora);

      digitalWrite(pin4, 0);
      digitalWrite(pin3, 0);
      digitalWrite(pin2, 0);
      digitalWrite(pin1, 0);

      delay(demora);

      Serial.read();
    }

  }

  // usarMotorConPot(A0, motor1);
  // usarMotorConPot(A1, motor2);
  // usarMotorConPot(A2, motor3);
  // usarMotorConPot(A3, motor4);

  // for (byte j = 5; j <= 135; j++) {
  //     motor1.write(j);
  //     motor2.write(j);
  //     motor3.write(j);

  //     delay(50);
  //     Serial.println(j);
  //     j++;
  // }

  // for (byte i = 135; i >= 5; i--) {
  //     motor1.write(i);
  //     motor2.write(i);
  //     motor3.write(i);

  //     delay(50);
  //     Serial.println(i);
  //     i--;
  // }

}

// void usarMotorConPot(int pinPot, Servo& motor) {
//   pote = analogRead(pinPot);
//   grados = map(pote, 0, 1023, 0, 180);
  
//   Serial.print("Potenciómetro A");
//   Serial.print(pinPot - A0);
//   Serial.print(": ");
//   Serial.println(grados);

//   motor.write(grados);

//   delay(10);
// }

