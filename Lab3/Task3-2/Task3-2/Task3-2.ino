const int ledPin = 6;
const int buttonPin = 2;
int lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '1') {
      digitalWrite(ledPin, HIGH);
    }
    if (command == '0') {
      digitalWrite(ledPin, LOW);
    }
  }
  int buttonState = digitalRead(buttonPin);
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