const int buttonPinA = 2;
const int ledPinA = 8;
const int buttonPinB = 4;
const int ledPinB = 9;
volatile bool ledStateA = false;
bool ledStateB = false;
bool lastButtonB = HIGH;

void setup() {
  pinMode(ledPinA, OUTPUT);
  pinMode(buttonPinA, INPUT_PULLUP);
  pinMode(ledPinB, OUTPUT);
  pinMode(buttonPinB, INPUT_PULLUP);

  attachInterrupt(
    digitalPinToInterrupt(buttonPinA),buttonISR,FALLING);
}
void buttonISR() {
  ledStateA = !ledStateA;
  digitalWrite(ledPinA, ledStateA);
}

void loop() {
  bool currentButtonB = digitalRead(buttonPinB);//Arduino主動去看ButtonB現在是HIGH還是LOW
  // 偵測 HIGH → LOW，也就是按下按鈕的瞬間
  if (lastButtonB == HIGH && currentButtonB == LOW) {
    ledStateB = !ledStateB;
    digitalWrite(ledPinB, ledStateB);
  }
  lastButtonB = currentButtonB;
  delay(2000);//2秒內Arduino根本沒有去檢查Button B
}