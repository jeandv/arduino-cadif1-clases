// CIRCUITO TINKERCAD = https://www.tinkercad.com/things/8p8Psofwgrk-desafio4arduinoivjeanrondon

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C pantalla(0x20,16,2);

const int PIN_SENSOR_HUMEDAD = A0;
const int PIN_BOMBA_MOTOR = 2;
const int PIN_SENSOR_TMP36 = A3;
const int PIN_RELE_CALENTADOR = 3;

int valorADCHumedad = 0;
int porcentajeHumedad = 0;
bool bombaActiva = false;
bool bombaApagadaPorAltaHumedad = false;
float temperaturaCelsius = 0;

void setup() {
  Serial.begin(9600);

  pantalla.init();
  pantalla.backlight();
  
  pantalla.setCursor(2, 0);
  pantalla.print("Bienvenidoo!");
  pantalla.setCursor(6, 1);
  pantalla.print(":D");

  delay(1000);
  pantalla.clear();

  pantalla.print("SISTEMA DE RIEGO");
  pantalla.setCursor(0, 1);
  pantalla.print("INICIANDO...");
  
  delay(2000);
  pantalla.clear();

  pinMode(PIN_BOMBA_MOTOR, OUTPUT);
  digitalWrite(PIN_BOMBA_MOTOR, 0);

  pinMode(PIN_RELE_CALENTADOR, OUTPUT);
  digitalWrite(PIN_RELE_CALENTADOR, 0);
}

void loop() {
  leerActualizarHumedad();
  controlarMotor();
  leerActualizarTemperatura();
  controlarCalentador();
  actualizarLCD();
  
  delay(100);
}

void leerActualizarHumedad() {
  valorADCHumedad = analogRead(PIN_SENSOR_HUMEDAD);
  porcentajeHumedad = map(valorADCHumedad, 0, 876, 0, 100);

  Serial.print("ADC Humedad: ");
  Serial.print(valorADCHumedad);
  Serial.print(" - ");
  Serial.print(porcentajeHumedad);
  Serial.println("% de Humedad");
}

void usarMotorIntermitente(long tiempoEncendido, long tiempoApagado) {
  bombaActiva = true;
  digitalWrite(PIN_BOMBA_MOTOR, 1);
  actualizarLCD();
  leerActualizarHumedad(); 

  while ((porcentajeHumedad < 10 && tiempoEncendido == 5000) ||
          (porcentajeHumedad >= 11 && porcentajeHumedad <= 50 && tiempoEncendido == 2000) ||
          (porcentajeHumedad >= 51 && porcentajeHumedad <= 80 && tiempoEncendido == 1000)) {
    
    if (porcentajeHumedad > 80) {
	  bombaActiva = false;
	  bombaApagadaPorAltaHumedad = true;
      break;
    }
    
	bombaActiva = true;
    digitalWrite(PIN_BOMBA_MOTOR, 1);
    actualizarLCD();  
    delay(tiempoEncendido);
    
	bombaActiva = false;
    digitalWrite(PIN_BOMBA_MOTOR, 0);
    actualizarLCD(); 
    delay(tiempoApagado);
    
    leerActualizarHumedad(); 
  }
  
  bombaActiva = false;
  digitalWrite(PIN_BOMBA_MOTOR, 0);
  leerActualizarHumedad(); 
}

void controlarMotor() {
  if (porcentajeHumedad > 80) {
    bombaApagadaPorAltaHumedad = true;
    bombaActiva = false;
    digitalWrite(PIN_BOMBA_MOTOR, 0);
  }

  if (bombaApagadaPorAltaHumedad && porcentajeHumedad < 10)
    bombaApagadaPorAltaHumedad = false;

  if (!bombaApagadaPorAltaHumedad) {
    int estadoHumedad;
    
    if (porcentajeHumedad <= 10)
       estadoHumedad = 0;
    else if (porcentajeHumedad >= 11 && porcentajeHumedad <= 50)
       estadoHumedad = 1;
    else if (porcentajeHumedad >= 51 && porcentajeHumedad <= 80)
       estadoHumedad = 2;
    else if (porcentajeHumedad > 80)
       estadoHumedad = 3;

    switch (estadoHumedad) {
      case 0:
        Serial.println("Humedad menor a 10% - Motor Bomba intermitente (5s ON, 1s OFF)");
        usarMotorIntermitente(5000, 1000);
        break;
      
      case 1:
        Serial.println("Humedad 11% entre 50% - Motor Bomba intermitente (2s ON, 2s OFF)");
        usarMotorIntermitente(2000, 2000);
        break;
        
      case 2:
        Serial.println("Humedad 51% entre 80% - Motor Bomba intermitente (1s ON, 5s OFF)");
        usarMotorIntermitente(1000, 5000);
        break;
        
      case 3:
        Serial.println("Humedad mayor 80% - Bomba Apagada");
        digitalWrite(PIN_BOMBA_MOTOR, 0);
        bombaActiva = false;
        bombaApagadaPorAltaHumedad = true;
        break;

      default:
        Serial.println("ERROR - Estado de humedad desconocido");
        break;
    }
    
  } else {
    bombaActiva = false;
    digitalWrite(PIN_BOMBA_MOTOR, 0);
    Serial.println("Humedad mayor a 80% - Motor Bomba Apagada (Esperando Humedad < 10%)");
  
  }
}

void leerActualizarTemperatura() {
  int valorADCTMP36 = analogRead(PIN_SENSOR_TMP36);
  float voltaje = valorADCTMP36 * (5.0 / 1024.0);
  temperaturaCelsius = (voltaje - 0.5) * 100;

  Serial.print("Temperatura: ");
  Serial.print(temperaturaCelsius, 1);
  Serial.println(" C");
}

void controlarCalentador() {
  leerActualizarTemperatura();
  actualizarLCD();

  if (temperaturaCelsius < 50) {
    
    Serial.println("Temperatura < 50C - Calentador ENCENDIDO");
    digitalWrite(PIN_RELE_CALENTADOR, 1);
    actualizarLCD();

    while (temperaturaCelsius < 50) {
      leerActualizarTemperatura();
      actualizarLCD();
      delay(500);
    }
    
    digitalWrite(PIN_RELE_CALENTADOR, 0);
    Serial.println("Temperatura en rango (>=50C) - Calentador APAGADO");
    actualizarLCD();  

  } else if (temperaturaCelsius > 60) {
    
    Serial.println("Temperatura > 60C - Calentador APAGADO (Fuera de rango por arriba)");
    digitalWrite(PIN_RELE_CALENTADOR, 0);
    actualizarLCD();
    
  } else {
    
    Serial.println("Temperatura en rango (50-60C) - Calentador APAGADO");
    digitalWrite(PIN_RELE_CALENTADOR, 0);
    actualizarLCD();
  
  }
}

void actualizarLCD() {
  pantalla.setCursor(0, 0);
  pantalla.print("Hum:");
  pantalla.print(porcentajeHumedad);
  pantalla.print("% ");

  pantalla.setCursor(0, 1);
  
  if (bombaActiva)
    pantalla.print("Bomba:ON   ");
  else
    pantalla.print("Bomba:OFF  ");

  if (bombaApagadaPorAltaHumedad) {
    pantalla.setCursor(0, 1);
    pantalla.print("Bomba:OFF");
  }

  pantalla.setCursor(8, 0);
  pantalla.print("Temp:");
  pantalla.print(temperaturaCelsius, 0);
  pantalla.print("C  ");

  pantalla.setCursor(10, 1);
  
  if (temperaturaCelsius >= 50 && temperaturaCelsius <= 60)
    pantalla.print("C OK  ");
  else if (temperaturaCelsius < 50)
    pantalla.print("C BAJA");
  else
    pantalla.print("C ALTA");
}