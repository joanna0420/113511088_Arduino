const int ledPin = 6;
const int buttonPin = 2;
int lastButtonState = HIGH;
//GUI跟Arduino做雙向UART Serial Communication
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
//按下按鈕後透過serial port傳送資料；Arduino端用Serial.begin(9600)持續接收資料，並依收到的內容控制LED
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {//字元
      digitalWrite(ledPin, HIGH);
    }
    if (command == '0') {
      digitalWrite(ledPin, LOW);
    }
  }
  int buttonState = digitalRead(buttonPin);//Two-way UART communication
  if (buttonState != lastButtonState) {
    if (buttonState == LOW) {
      Serial.println("Button Pressed!");
    } else {
      Serial.println("Button Released!");
    }
    lastButtonState = buttonState;
    delay(50);
  }
}