#include "motor.h"
void motor_setup_pins(void){
  //MOTOR PINS
  
  pwm_duty_cycle_set(90);
 pinMode(MOTOR_PIN_1,OUTPUT); 
 pinMode(MOTOR_PIN_2,OUTPUT); 
//PWM SPEED CONTROL
 pinMode(MOTOR_SPEED_PIN,OUTPUT); 
 timer_pwm_speed_control(FAST_PWM_MAX_TOP_MAX_OVER_FLOW,FAST_PWM_NON_INVERTING);
}
void motor_turn_on(void){
  digitalWrite(MOTOR_PIN_1,HIGH);
  digitalWrite(MOTOR_PIN_1,LOW);
 
  pwm_freq_config(1000); 
 
  
}
void motor_stop(void){
  digitalWrite(MOTOR_PIN_1,HIGH);
  digitalWrite(MOTOR_PIN_1,LOW);
  
 pwm_stop();
}
