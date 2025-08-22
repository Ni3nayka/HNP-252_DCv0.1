/*
  https://github.com/Ni3nayka/HNP-252_DCv0.1

  author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
  write:  Jan 2025
  modify: August 2025
*/   

#include <HNP-252_DCv0_1.h>
MotorShield motors;

void setup() {
  motors.setup();
  // forward
  for (int i = 0; i <= 100; i++) {
    motors.runs(i, i);
    delay(50);
  }
  delay(500);
  for (int i = 100; i >= 0; i--) {
    motors.runs(i, i);
    delay(50);
  }
  delay(500);
  // backward
  for (int i = 0; i <= 100; i++) {
    motors.runs(-i, -i);
    delay(50);
  }
  delay(500);
  for (int i = 100; i >= 0; i--) {
    motors.runs(-i, -i);
    delay(50);
  }
  delay(500);
  // left
  for (int i = 0; i <= 100; i++) {
    motors.runs(-i, i);
    delay(50);
  }
  delay(500);
  for (int i = 100; i >= 0; i--) {
    motors.runs(-i, i);
    delay(50);
  }
  delay(500);
  // right
  for (int i = 0; i <= 100; i++) {
    motors.runs(i, -i);
    delay(50);
  }
  delay(500);
  for (int i = 100; i >= 0; i--) {
    motors.runs(i, -i);
    delay(50);
  }
  delay(500);
}

void loop() {}
