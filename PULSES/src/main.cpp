#include <Arduino.h>
#define FREQUENCY 1000
#define TIME 3
#define PIN 3

void send_pulses() {
  int x = 1000000 / FREQUENCY / 2;
  int pulse_count = TIME * FREQUENCY;
  int timer = millis();

  for (int i = 0; i < pulse_count; i++) {
    digitalWrite(PIN, LOW);
    delayMicroseconds(x);
    digitalWrite(PIN, HIGH);
    delayMicroseconds(x);
  }
  digitalWrite(PIN, LOW);

  timer = millis() - timer;
  Serial.print("Time [s]: ");
  Serial.println(timer / 1000);
  Serial.print("Num pulses: ");
  Serial.println(pulse_count);
  Serial.print("Average frequency [Hz]: ");
  Serial.println((pulse_count / (timer / 1000)));
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
