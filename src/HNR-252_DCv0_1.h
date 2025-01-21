/*
   https://github.com/Ni3nayka/HNR-252_DCv0.1

   author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
   write:  Jan 2025
   modify: Jan 2025
*/  

#pragma once

#ifndef ESP32 
#error "lib not supported this board"
#endif

#define HNR_252_DC_V0_1_PWM2_1 23
#define HNR_252_DC_V0_1_PWM2_2 19
#define HNR_252_DC_V0_1_PWM2_3 14
#define HNR_252_DC_V0_1_PWM2_4 27

#define HNR_252_DC_V0_1_PWM1_1 18
#define HNR_252_DC_V0_1_PWM1_2 4
#define HNR_252_DC_V0_1_PWM1_3 13
#define HNR_252_DC_V0_1_PWM1_4 12

class MotorShield {
  public:
    void setup() {
      pinMode(HNR_252_DC_V0_1_PWM1_1, OUTPUT);
      pinMode(HNR_252_DC_V0_1_PWM1_2, OUTPUT);
      pinMode(HNR_252_DC_V0_1_PWM1_3, OUTPUT);
      pinMode(HNR_252_DC_V0_1_PWM1_4, OUTPUT);
      pinMode(HNR_252_DC_V0_1_PWM2_1, OUTPUT);
      pinMode(HNR_252_DC_V0_1_PWM2_2, OUTPUT);
      pinMode(HNR_252_DC_V0_1_PWM2_3, OUTPUT);
      pinMode(HNR_252_DC_V0_1_PWM2_4, OUTPUT);
      MotorShield::runs();
    }
    void run_1(int speed=0) {
      MotorShield::run_motor(HNR_252_DC_V0_1_PWM1_1, HNR_252_DC_V0_1_PWM2_1, HNR_252_DC_V0_1_PWM1_2, HNR_252_DC_V0_1_PWM2_2, speed);
    }
    void run_2(int speed=0) {
      MotorShield::run_motor(HNR_252_DC_V0_1_PWM1_3, HNR_252_DC_V0_1_PWM2_3, HNR_252_DC_V0_1_PWM1_4, HNR_252_DC_V0_1_PWM2_4, speed);
    }
    void run(int number, int speed=0) {
      if (number==1) MotorShield::run_1(speed);
      if (number==2) MotorShield::run_2(speed);
    }
    void runs(int speed_a = 0, int speed_b = 0) {
      MotorShield::run_1(speed_a);
      MotorShield::run_2(speed_b);
    }
  private:
    void run_motor(int pwm1_a, int pwm2_a, int pwm1_b, int pwm2_b, int speed) {
      analogWrite(pwm1_a,constrain(speed,0,100)*2.5);
      analogWrite(pwm2_a,constrain(-speed,0,100)*2.5);
      digitalWrite(pwm1_b,speed<0);
      digitalWrite(pwm2_b,speed>0);
    }
};