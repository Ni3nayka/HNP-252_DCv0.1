/*
   https://github.com/Ni3nayka/HNP-252_DCv0.1

   author: Egor Bakay <egor_bakay@inbox.ru> Ni3nayka
   write:  Jan 2025
   modify: August 2025
*/  

#pragma once

#if (!(defined(__AVR_ATmega328P__) || defined(ESP32)))
#error "lib not supported this board"
#endif


#ifdef ESP32

// HNP-252 DCv0.1
#define HNP_252_DC_V0_1_PWM2_1 23
#define HNP_252_DC_V0_1_PWM2_2 19
#define HNP_252_DC_V0_1_PWM2_3 14
#define HNP_252_DC_V0_1_PWM2_4 27
#define HNP_252_DC_V0_1_PWM1_1 18
#define HNP_252_DC_V0_1_PWM1_2 4
#define HNP_252_DC_V0_1_PWM1_3 13
#define HNP_252_DC_V0_1_PWM1_4 12

#else

// L298P amperka
#define HNP_252_DC_V0_1_PWM1 5
#define HNP_252_DC_V0_1_DIR1 4
#define HNP_252_DC_V0_1_PWM2 6
#define HNP_252_DC_V0_1_DIR2 7

#endif

class MotorShield {
  public:
    void setup() {
      #ifdef ESP32
      pinMode(HNP_252_DC_V0_1_PWM1_1, OUTPUT);
      pinMode(HNP_252_DC_V0_1_PWM1_2, OUTPUT);
      pinMode(HNP_252_DC_V0_1_PWM1_3, OUTPUT);
      pinMode(HNP_252_DC_V0_1_PWM1_4, OUTPUT);
      pinMode(HNP_252_DC_V0_1_PWM2_1, OUTPUT);
      pinMode(HNP_252_DC_V0_1_PWM2_2, OUTPUT);
      pinMode(HNP_252_DC_V0_1_PWM2_3, OUTPUT);
      pinMode(HNP_252_DC_V0_1_PWM2_4, OUTPUT);
      #else
      pinMode(HNP_252_DC_V0_1_PWM1, OUTPUT);
      pinMode(HNP_252_DC_V0_1_DIR1, OUTPUT);
      pinMode(HNP_252_DC_V0_1_PWM2, OUTPUT);
      pinMode(HNP_252_DC_V0_1_DIR2, OUTPUT);
      #endif
      MotorShield::runs();
    }
    void run_1(int speed=0) {
      #ifdef ESP32
      MotorShield::run_motor(HNP_252_DC_V0_1_PWM1_1, HNP_252_DC_V0_1_PWM2_1, HNP_252_DC_V0_1_PWM1_2, HNP_252_DC_V0_1_PWM2_2, speed);
      #else
      MotorShield::run_motor(HNP_252_DC_V0_1_PWM1, HNP_252_DC_V0_1_DIR1, speed);
      #endif
    }
    void run_2(int speed=0) {
      #ifdef ESP32
      MotorShield::run_motor(HNP_252_DC_V0_1_PWM1_3, HNP_252_DC_V0_1_PWM2_3, HNP_252_DC_V0_1_PWM1_4, HNP_252_DC_V0_1_PWM2_4, speed);
      #else
      MotorShield::run_motor(HNP_252_DC_V0_1_PWM2, HNP_252_DC_V0_1_DIR2, speed);
      #endif
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
    #ifdef ESP32
    void run_motor(int pwm1_a, int pwm2_a, int pwm1_b, int pwm2_b, int speed) {
      analogWrite(pwm1_a,constrain(speed,0,100)*2.5);
      analogWrite(pwm2_a,constrain(-speed,0,100)*2.5);
      digitalWrite(pwm1_b,speed<0);
      digitalWrite(pwm2_b,speed>0);
      delay(5); // было проверено, что без этого перестает работать ШИМ
    }
    #else
    void run_motor(int pwm, int dir, int speed) {
      analogWrite(pwm,constrain(abs(speed),0,100)*2.5);
      digitalWrite(dir,speed>0);
    }
    #endif
};
