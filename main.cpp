#include <Arduino.h>

// 設定腳位 
int led1 = 3; 
int led2 = 4;
int trigPin = 11;
int echoPin = 12;
long duration, cm;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT); // 設定led1為輸出腳位
  pinMode(led2, OUTPUT); // 設定led2為輸出腳位
  pinMode(trigPin, OUTPUT); // 設定trigPin為輸出腳位
  pinMode(echoPin, INPUT); // 設定echoPin為輸出腳位
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH); // trigPin發射
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT); // echoPin接收
  duration = pulseIn(echoPin, HIGH); // 當echoPin收到訊號 設為HIGH

  cm = (duration/2) / 29.1;
  
  if(cm < 15){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }

  delay(250);
}