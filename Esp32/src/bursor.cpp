#include "Arduino.h"

# define Buzzer 1
#define Button 2

void setup() {
  // put your setup code here, to run once:
  pinMode(Buzzer, OUTPUT);
  pinMode(Button, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(Button) == HIGH) {
    digitalWrite(Buzzer, HIGH);
    serial.println("Button is pressed");
  } else {
    digitalWrite(Buzzer, LOW);
    serial.println("Button is not pressed");
  }
}
