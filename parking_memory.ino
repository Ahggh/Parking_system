#include "parking_memory.h"
void memory_init(void){
      

 if(EEPROM.read(0x00)!=1)   
  {
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print("MEMORY INIT MODE");
     //delay(50);
     for(counter=0;counter<=400;counter++)
        {
           EEPROM.write(0x01+counter,0x00);
        }
        //initilaze digits
        EEPROM.write(0x00,1);
         for(counter=0;counter<6;counter++)
        {
          for(counter_2=0;counter_2<4;counter_2++)
          {
            EEPROM.write(address_rand_code+counter_2,counter_2);
          }
          address_rand_code+=4;
        } 
   
   //-----------------------------------------------
     if(Read_ir_sensor(IR_SENSOR_1)!=1)
     {
      motor_turn_on();
      while(Read_ir_sensor(IR_SENSOR_1)!=1);
      motor_stop();
      }
      lcd.clear();
       lcd.setCursor(0,0);
      lcd.print("Enter Number");
      lcd.setCursor(0,2);
      lcd.print("Intial_pack:");
     delay(600);
     car_counter=write_number_keypad();
    lcd.setCursor(12,2);
    lcd.print(car_counter);
     delay(600);
    EEPROM.write(COUNTER_PACK_ADD,car_counter); 
     lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("MEMORY INIT");
       lcd.setCursor(0,1);
      lcd.print("DONE");
      delay(1000);
     
      
        //initilaze digits
        uint8_t counter_pack_temp=0;
           for(counter=0;counter<6;counter++)
          {
          for(counter_2=0;counter_2<2;counter_2++)
          {
            
            if(counter_2==0) EEPROM.write(address_pack_states,++counter_pack_temp);
           if(counter_2==1) EEPROM.write(address_pack_states+counter_2,0);
          }
            address_pack_states+=2;
        } 
   
  
     }
  
}

//operations in Memory
void eeprom_write_operation(uint8_t operation_type,uint8_t data)
{
 switch(operation_type)
  {
    case COUNTER_PACK_OPERATION :
    EEPROM.write(operation_type,data);
      break; 
    case COUNTER_NUMBER_PACK_STATE_OPERATION :
    
      break; 
     case PACK_CODES_OPERATION :
     
        break;
     case GENERAL_PARKING_STATE :
     
        break;
     default:;
      
  }
}
