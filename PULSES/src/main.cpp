#include <Arduino.h>
#define FREQUENCY 200
#define TIME 15
#define PIN 3

void send_pulses() {
  int x = 1000000 / FREQUENCY / 2;
  int pulse_count = TIME * FREQUENCY;

  Serial.print("Expected duration [s]: ");
  Serial.println(TIME);
  Serial.print("Expected number of pulses: ");
  Serial.println(pulse_count);

  int timer = millis();
  for (int i = 0; i < pulse_count; i++) {
    digitalWrite(PIN, LOW);
    delayMicroseconds(x);
    digitalWrite(PIN, HIGH);
    delayMicroseconds(x);
  }
  digitalWrite(PIN, LOW);

  timer = millis() - timer;
  Serial.print("Actual duration [s]: ");
  Serial.println(timer / 1000.0);
  Serial.print("Average frequency [Hz]: ");
  Serial.println(pulse_count / (timer / 1000.0));
}


void setup() {
  // put your setup code here, to run once:
  pinMode(PIN , OUTPUT);
  digitalWrite(PIN, LOW);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while (Serial.available() == 0) {/* Spin. */}
  String s = Serial.readString();
  Serial.println(s);
  if (s.equals("GO"))
    send_pulses();
}
