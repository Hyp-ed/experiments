#include <Arduino.h>
#define FREQUENCY 1000
#define TIME 3

void setup() {
  // put your setup code here, to run once:
  pinMode( 3 , OUTPUT);

  Serial.begin(9600); 
  
  int x = 1000000 / FREQUENCY / 2;
  int pulse_count = TIME * FREQUENCY;
  int timer = millis();

  for (int i = 0; i < pulse_count; i++) {
    digitalWrite(3, HIGH);
    delayMicroseconds(x);
    digitalWrite(3, LOW);
    delayMicroseconds(x);  
    }
  
  timer = millis() - timer;
  Serial.println(timer);
  Serial.println((pulse_count / (timer / 1000)));
  Serial.println(pulse_count);
}
  
void loop() {
  // put your main code here, to run repeatedly:  
}