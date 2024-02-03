#include "Arduino.h"

# define LED_BUILTIN 2

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}
void loop() {
  // Fast blinking
  for(int i = 0; i < 10; i++) { // blink for 10 times
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
    delay(100); // wait for 100ms
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off
    delay(100); // wait for 100ms
  }
  delay(1000); // wait for a second before slow blinking

  // Slow blinking
  for(int i = 0; i < 10; i++) { // blink for 10 times
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
    delay(1000); // wait for a second
    digitalWrite(LED_BUILTIN, LOW); // turn the LED off
    delay(1000); // wait for a second
  }
}