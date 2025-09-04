#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// -------------------- PCA9685 Setup --------------------
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40); // default address 0x40

// Choose your servo pulse range (microseconds). Adjust if your servos need it.
const int SERVO_US_MIN = 500;   // ~0°  (change to ~600–700 if needed)
const int SERVO_US_MAX = 2500;  // ~180° (change to ~2300 if needed)

// PCA9685 runs at 50–60 Hz for servos
const float SERVO_PWM_HZ = 50.0f;

// Map your three servos to PCA9685 channels
#define SERVO1_CH 0
#define SERVO2_CH 1
#define SERVO3_CH 2

// -------------------- Motion / State --------------------
int pos1 = 0, pos2 = 0, pos3 = 0;
bool left1 = false, right1 = false;
bool left2 = false, right2 = false;
bool left3 = false, right3 = false;

// -------------------- Helpers --------------------

// Convert angle (0–180) to microseconds (SERVO_US_MIN..SERVO_US_MAX)
int angleToMicros(int angle) {
  angle = constrain(angle, 0, 180);
  return map(angle, 0, 180, SERVO_US_MIN, SERVO_US_MAX);
}

// Write an angle to a PCA9685 channel
void writeAngle(uint8_t ch, int angle) {
  int us = angleToMicros(angle);
  // Adafruit lib has writeMicroseconds(ch, us)
  pwm.writeMicroseconds(ch, us);
}

// Sweep from 'fromDeg' to 'toDeg' on a channel
void sweep(uint8_t ch, int &posRef, int fromDeg, int toDeg, int stepDeg, int delayMs, const char *label) {
  if (fromDeg <= toDeg) {
    for (posRef = fromDeg; posRef <= toDeg; posRef += stepDeg) {
      writeAngle(ch, posRef);
      delay(delayMs);
      if (label) Serial.println(label);
    }
  } else {
    for (posRef = fromDeg; posRef >= toDeg; posRef -= stepDeg) {
      writeAngle(ch, posRef);
      delay(delayMs);
      if (label) Serial.println(label);
    }
  }
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Initialize PCA9685
  pwm.begin();
  // Optional: set the internal oscillator if your board needs it
  // pwm.setOscillatorFrequency(27000000); // uncomment if pulses look off
  pwm.setPWMFreq(SERVO_PWM_HZ);

  // Move servos to a known safe position (0°)
  writeAngle(SERVO1_CH, 0);
  writeAngle(SERVO2_CH, 0);
  writeAngle(SERVO3_CH, 0);

  Serial.println("PCA9685 Servo Driver Ready.");
}

void loop() {
  // Read a single character command if available
  if (Serial.available() > 0) {
    char c = (char)Serial.read();

    // ---------------- SERVO 1 ----------------
    // Original: 'Q' triggered a full left then right cycle
    if ((c == 'Q' || c == 'q') && left1 == false) {
      left1  = true;
      right1 = false;

      // 0 -> 180
      sweep(SERVO1_CH, pos1, 0, 180, 1, 5, "Servo1: Left");
      // 180 -> 0
      right1 = true;
      left1  = false;
      sweep(SERVO1_CH, pos1, 180, 0, 1, 5, "Servo1: Right");
    }

    // ---------------- SERVO 2 ----------------
    // 'A' goes 0->180, 'S' goes 180->0
    if ((c == 'A' || c == 'a') && left2 == false) {
      left2  = true;
      right2 = false;
      sweep(SERVO2_CH, pos2, 0, 180, 1, 5, "Servo2: Left");
    } else if ((c == 'S' || c == 's') && right2 == false) {
      right2 = true;
      left2  = false;
      sweep(SERVO2_CH, pos2, 180, 0, 1, 5, "Servo2: Right");
    }

    // ---------------- SERVO 3 ----------------
    // 'Z' goes 0->180, 'X' goes 180->0
    if ((c == 'Z' || c == 'z') && left3 == false) {
      left3  = true;
      right3 = false;
      sweep(SERVO3_CH, pos3, 0, 180, 1, 5, "Servo3: Left");
    } else if ((c == 'X' || c == 'x') && right3 == false) {
      right3 = true;
      left3  = false;
      sweep(SERVO3_CH, pos3, 180, 0, 1, 5, "Servo3: Right");
    }
  }
}
