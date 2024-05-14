
#include <LiquidCrystal.h>

#include "parking_memory.h"



LiquidCrystal lcd(A0, A1, A2, A3, A4, A5); 
unsigned short  counter=0;
unsigned short  counter_2=0;

uint8_t car_number[4];

uint8_t car_rand_code[4];

uint8_t empty_pack=0;
uint8_t pack_state=0;


uint8_t Button_Flag=0;
  
