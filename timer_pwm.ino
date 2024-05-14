 #include "timer_pwm.h"
  void timer_pwm_speed_control(uint8_t timer_mode,uint8_t timer_sub_mode){
 //STOP_TIMER_CLK
  TCCR2B&=~0X07;
  
   { TCCR2A|=(timer_mode&0X03);
     TCCR2B|=((timer_mode&0X04)<<3);} 
     //SET _SUB MODE
  TCCR2A|=(timer_sub_mode<<6);
  
  
}
void pwm_freq_config(uint16_t pwm_freq){
  //SET_PRESCALER FOR PWM
  uint16_t prescaler_val;
prescaler_val=((8000000.0)/(256.0*pwm_freq));


if((prescaler_val<=0))
  {
    TCCR2B|=PRESCALER_NO;
  }
else if((prescaler_val>0)&&(prescaler_val<=8))
  {
    TCCR2B|=PRESCALER_8;
  }
 else if((prescaler_val>8)&&(prescaler_val<=32))
  {
    TCCR2B|=PRESCALER_32;
  }
  else if((prescaler_val>32)&&(prescaler_val<=64))
  {
    TCCR2B|=PRESCALER_64;
  }
  else if((prescaler_val>64)&&(prescaler_val<=128))
  {
    TCCR2B|=PRESCALER_128;
  }
  else if((prescaler_val>128)&&(prescaler_val<=256))
  {
    TCCR2B|=PRESCALER_256;
  }
   else if((prescaler_val>256)&&(prescaler_val<=1024))
  {
    TCCR2B|=PRESCALER_1024;
  }
  else
    {
      /*NOTHING*/
    }
}


void pwm_duty_cycle_set(uint8_t duty_cyle){
uint8_t out_duty_cycle;
duty_cyle=((duty_cyle/100.0)*(256.0))-1;
OCR2A=duty_cyle;
}
void pwm_stop(void){
//STOP_TIMER_CLK
 TCCR2A&=~0XC0;
}
