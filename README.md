# Robo Hand: Rock-Paper-Scissors

This repository contains the Arduino UNO sketch and documentation for building a robotic hand that plays Rock-Paper-Scissors using two servo motors and a push-button input. When the button is pressed, the hand randomly chooses one of the three gestures:

* ✊ **Rock** (fist)
* ✋ **Paper** (flat hand)
* ✌️ **Scissors** (two fingers extended)

---

## Features

* Randomized gesture selection on button press
* Two servos controlling finger movements
* Easily customizable open/closed positions and timing

---

## Hardware Requirements

* Arduino UNO
* 2 × Standard hobby servo motors (e.g., SG90)
* Momentary push-button
* 2 × 10 kΩ resistors (for pull-down wiring option) or use internal pull-up
* Breadboard and jumper wires
* External 5 V power source for servos (recommended)

---

## Wiring Diagram

1. **Servos**

   * Servo 1 signal → Arduino pin 9
   * Servo 2 signal → Arduino pin 10
   * Servo VCC → 5 V (external supply recommended)
   * Servo GND → Arduino GND (common ground)

2. **Button** (using internal pull-up):

   * Button one leg → Arduino pin 2
   * Button other leg → GND

   (Alternatively, wire as pull-down with 10 kΩ resistor between pin and GND.)

---

## Installation & Usage

1. Clone this repository:

   ```bash
   git clone https://github.com/yourusername/robo-hand-rps.git
   cd robo-hand-rps
   ```

2. Open `RoboHandRPS.ino` in the Arduino IDE.

3. Verify your board and port under **Tools**.

4. Upload the sketch to your Arduino UNO.

5. Press the push-button to make the hand play Rock-Paper-Scissors!

---

## Code Overview

* **RoboHandRPS.ino**: Main Arduino sketch.

  * Sets up servos and button input.
  * On button press, selects a random gesture (0, 1, 2) corresponding to Rock, Paper, or Scissors.
  * Moves servos to predefined angles:

    * Rock: both servos to `CLOSE_POS` (0°)
    * Paper: both servos to `OPEN_POS` (180°)
    * Scissors: one servo open, one servo closed

* **Constants you can tweak**:

  * `OPEN_POS`, `CLOSE_POS`: Servo angles for open vs. closed positions.
  * `HOLD_TIME`: How long the gesture is held before resetting.
  * `SERVO1_PIN`, `SERVO2_PIN`, `BUTTON_PIN`: Pin assignments.

---

## Customization

* **Change Gesture Angles**: Adjust `OPEN_POS` and `CLOSE_POS` to fit your mechanical design.
* **Add More Gestures**: Expand the `switch(pattern)` block in `loop()` for additional finger combinations.
* **Adjust Timing**: Modify `HOLD_TIME` to control how long each gesture stays active.

---

## Troubleshooting

* **Servo jitter or insufficient torque**: Use an external 5 V supply capable of ≥1 A per servo.
* **Button not responding**: Confirm wiring and use `INPUT_PULLUP` or an external resistor correctly.
* **Random seed not working**: Ensure analog pin A0 is left floating or connect to a noise source.

---

## License

This project is released under the MIT License. See [LICENSE](LICENSE) for details.
