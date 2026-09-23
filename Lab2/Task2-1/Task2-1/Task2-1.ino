const int PIN_1A = 8;
const int PIN_2A = 9;
const int PIN_EN = 5;

const int POT_PIN = A0;

void setup() {
  pinMode(PIN_1A, OUTPUT);
  pinMode(PIN_2A, OUTPUT);
  pinMode(PIN_EN, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  int potValue = analogRead(POT_PIN);
  Serial.println(potValue);
  if (potValue < 480) {
    digitalWrite(PIN_1A, LOW);
    digitalWrite(PIN_2A, HIGH);
    int speed = map(potValue, 480, 0, 0, 255);
    analogWrite(PIN_EN, speed);
  }
  else if (potValue > 544) {
    digitalWrite(PIN_1A, HIGH);
    digitalWrite(PIN_2A, LOW);
    int speed = map(potValue, 544, 1023, 0, 255);
    analogWrite(PIN_EN, speed);
  }
  else {
    digitalWrite(PIN_1A, LOW);
    digitalWrite(PIN_2A, LOW);
    analogWrite(PIN_EN, 0);
  }
  delay(10);
}
