#include <SoftwareSerial.h>
const int ledPin = 6;
const int buttonPin = 2;
const int bluetoothRX = 10;
const int bluetoothTX = 11;
//USB Serial改成Bluetooth Serial
SoftwareSerial bluetooth(bluetoothRX, bluetoothTX);//TX-RX RX-TX
//SoftwareSerial讓Arduino用D10、D11建另一組serial port，因此HC-05不需要占用D0/D1的hardware Serial
int lastButtonState = HIGH;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  bluetooth.begin(9600);
}
void loop() {
  if (bluetooth.available() > 0) {//HC-05有沒有收到從電腦傳來的資料
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