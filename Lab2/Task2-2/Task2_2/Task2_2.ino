#include <Servo.h>
Servo myservo;
const int trigPin = 7;
const int echoPin = 6;
void setup() {
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);// 接收反射回來的時間
  int distance = duration * 0.034 / 2;
  distance = constrain(distance, 5, 30);
  int angle = map(distance, 5, 30, 0, 180);
  myservo.write(angle);
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.print(" cm, Angle = ");
  Serial.println(angle);
  delay(100);
}