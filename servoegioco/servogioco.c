#include <Adafruit_TCS34725.h>
#include <Servo.h>

// Inizializza i sensori di colore
Adafruit_TCS34725 tcs1 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 tcs2 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 tcs3 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);
Adafruit_TCS34725 tcs4 = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

// Inizializza i servo motori
Servo servo1, servo2, servo3, servo4;

// Pin dei servo
const int servoPin1 = 3;
const int servoPin2 = 5;
const int servoPin3 = 6;
const int servoPin4 = 9;

// Posizioni dei servo
const int servoUp = 90;
const int servoDown = 30;

void setup() {
  Serial.begin(9600);

  // Attacca i servo ai pin
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);
  servo4.attach(servoPin4);

  // Porta i servo alla posizione iniziale
  servo1.write(servoUp);
  servo2.write(servoUp);
  servo3.write(servoUp);
  servo4.write(servoUp);

  // Inizializza i sensori di colore
  if (!tcs1.begin() || !tcs2.begin() || !tcs3.begin() || !tcs4.begin()) {
    Serial.println("Errore: impossibile inizializzare i sensori di colore.");
    while (1);
  }
}

void loop() {
  // Variabili per i valori di colore
  uint16_t r, g, b, c;

  // Leggi il primo sensore
  tcs1.getRawData(&r, &g, &b, &c);
  if (isColorDetected(r, g, b)) {
    moveServo(servo1);
  }

  // Leggi il secondo sensore
  tcs2.getRawData(&r, &g, &b, &c);
  if (isColorDetected(r, g, b)) {
    moveServo(servo2);
  }

  // Leggi il terzo sensore
  tcs3.getRawData(&r, &g, &b, &c);
  if (isColorDetected(r, g, b)) {
    moveServo(servo3);
  }

  // Leggi il quarto sensore
  tcs4.getRawData(&r, &g, &b, &c);
  if (isColorDetected(r, g, b)) {
    moveServo(servo4);
  }

  delay(100); // Piccola pausa per evitare letture continue
}

bool isColorDetected(uint16_t r, uint16_t g, uint16_t b) {
  // Esempio: rileva un colore rosso predominante
  return (r > g * 1.5 && r > b * 1.5);
}

void moveServo(Servo &servo) {
  servo.write(servoDown);
  delay(900); // Poco meno di un secondo
  servo.write(servoUp);
}
