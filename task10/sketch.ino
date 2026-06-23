#include <Servo.h>

Servo servo;
const int servo_pin = 3;
const int step_delay = 15;
int current_angle = 0;

void setup() {
  Serial.begin(9600);
  servo.attach(servo_pin);
  servo.write(current_angle);
  Serial.println("System initialized.");
  Serial.println("Please enter an angle between 0 and 180:");
}

void loop() {
  if (Serial.available() > 0) {
    int target_angle = Serial.parseInt();
    while (Serial.available() > 0) {
      Serial.read();
    }
    if (target_angle < 0 || target_angle > 180) {
      Serial.println("Error: Invalid angle! Please enter a value from 0 to 180.");
      return;
    }
    if (target_angle == current_angle) {
      Serial.println("The servo is already at this angle.");
      return;
    }
    Serial.print("Moving from ");
    Serial.print(current_angle);
    Serial.print(" to ");
    Serial.println(target_angle);
    int step = (target_angle > current_angle) ? 1 : -1;
    while (current_angle != target_angle) {
      current_angle += step;
      servo.write(current_angle);
      delay(step_delay);
    }
    Serial.println("Target angle reached.");
  }
}