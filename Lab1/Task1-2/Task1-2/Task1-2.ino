int redPin = 9;
int greenPin = 10;
int bluePin = 11;
int buttonPin = 2;
int potPin = A0;
int greenState = 0;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Green Light Brightness Controller");
}
void loop() {
  // 藍色
  int analogValue = analogRead(potPin);
  int blueBrightness = map(analogValue, 0, 1023, 0, 255);
  analogWrite(bluePin, blueBrightness);
  // 紅色
  if (digitalRead(buttonPin) == LOW) {
    analogWrite(redPin, 255);
  }
  else {
    analogWrite(redPin, 0);
  }
  // 綠色
  if (Serial.available() > 0) {
    char input = Serial.read();
    if (input == '1') {
      greenState = 255;
      Serial.print("Green Light Brightness: ");
      Serial.println(greenState);
    }
    else if (input == '0') {
      greenState = 0;
      Serial.print("Green Light Brightness: ");
      Serial.println(greenState);
    }
  }
  analogWrite(greenPin, greenState);
  delay(10);
}