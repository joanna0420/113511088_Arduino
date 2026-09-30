#include <SoftwareSerial.h>
const int ledPin = 6;
const int buttonPin = 2;
const int bluetoothRX = 10;
const int bluetoothTX = 11;
SoftwareSerial bluetooth(bluetoothRX, bluetoothTX);
int lastButtonState = HIGH;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  bluetooth.begin(9600);
}
void loop() {
  if (bluetooth.available() > 0) {
    char command = bluetooth.read();
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
    }
    if (command == '0') {
      digitalWrite(ledPin, LOW);
    }
  }
  int buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    delay(50);
    buttonState = digitalRead(buttonPin);
    if (buttonState != lastButtonState) {
      if (buttonState == LOW) {
        bluetooth.println("Button Pressed!");
      } else {
        bluetooth.println("Button Released!");
      }
      lastButtonState = buttonState;
    }
  }
}