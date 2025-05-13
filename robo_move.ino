#include <Servo.h>

// — USER CONFIG —
// Servo pins
const uint8_t SERVO1_PIN = 9;
const uint8_t SERVO2_PIN = 10;
// Button pin (uses INPUT_PULLUP)
const uint8_t BUTTON_PIN = 2;

// “Open” and “Closed” angles
const uint8_t OPEN_POS  = 0;
const uint8_t CLOSE_POS = 180;

// How long to hold each position (ms)
const unsigned long HOLD_TIME = 500;

Servo s1, s2;

void setup() {
  s1.attach(SERVO1_PIN);
  s2.attach(SERVO2_PIN);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  randomSeed(analogRead(A0));

  // start closed
  s1.write(CLOSE_POS);
  s2.write(CLOSE_POS);
}

void loop() {
  // wait for button press
  if (digitalRead(BUTTON_PIN) == LOW) {
    // pick one of 4 patterns
    int pattern = random(0, 4);
    switch (pattern) {
      case 0:
        // both open
        s1.write(OPEN_POS);
        s2.write(OPEN_POS);
        break;
      case 1:
        // both closed
        s1.write(CLOSE_POS);
        s2.write(CLOSE_POS);
        break;
      case 2:
        // s1 open, s2 closed
        s1.write(OPEN_POS);
        s2.write(CLOSE_POS);
        break;
      case 3:
        // s1 closed, s2 open
        s1.write(CLOSE_POS);
        s2.write(OPEN_POS);
        break;
    }

    delay(HOLD_TIME);

    // simple debounce: wait for release
    while (digitalRead(BUTTON_PIN) == LOW) { /* do nothing */ }
    delay(50);
  }
}
