int potPin = A0;     
int ledPin = 9;     
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int analogValue = analogRead(potPin);
  int brightness = map(analogValue, 0, 1023, 0, 255);
  analogWrite(ledPin, brightness);
  Serial.print("Data is ");
  Serial.println(analogValue);
  delay(500);
}
