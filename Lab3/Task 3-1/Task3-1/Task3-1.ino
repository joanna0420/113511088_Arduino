#include <TimerOne.h>
const int buttonA = 2;
const int ledA = 6;
const int buttonB = 3;
const int ledB = 7;
void timerISR() {
  if (digitalRead(buttonA) == LOW) {
    digitalWrite(ledA, HIGH);
  } else {
    digitalWrite(ledA, LOW);
  }
}
void setup() {
  pinMode(buttonA, INPUT_PULLUP);
  pinMode(buttonB, INPUT_PULLUP);
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  Timer1.initialize(50000);
  Timer1.attachInterrupt(timerISR);
}
void loop() {
  if (digitalRead(buttonB) == LOW) {
    digitalWrite(ledB, HIGH);
  } else {
    digitalWrite(ledB, LOW);
  }
  delay(1000);
}