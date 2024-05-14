#include "Interface_control.h"
void pack_states_edit(uint8_t pack_selected,uint8_t operation_type){
   if(operation_type==NEW_CAR)
    switch(pack_selected)
       {
        case 1:
       EEPROM.write(COUNTER_NUMBER_PACK_STATE_1,PACK_FILL);
        break;
        case 2:
          EEPROM.write(COUNTER_NUMBER_PACK_STATE_2,PACK_FILL);
        break;
        case 3:
        EEPROM.write(COUNTER_NUMBER_PACK_STATE_3,PACK_FILL);
        break;
        case 4:
         EEPROM.write(COUNTER_NUMBER_PACK_STATE_4,PACK_FILL);
        break;
        case 5:
         EEPROM.write(COUNTER_NUMBER_PACK_STATE_5,PACK_FILL);
        break;
        case 6:
         EEPROM.write(COUNTER_NUMBER_PACK_STATE_6,PACK_FILL);
        break;
        default :/*NOTHING ELSE*/;
        } 
        else if(operation_type==RETURN_CAR)
        {
          switch(pack_selected)
       {
        case 1:
       EEPROM.write(COUNTER_NUMBER_PACK_STATE_1,PACK_EMPTY);
        break;
        case 2:
          EEPROM.write(COUNTER_NUMBER_PACK_STATE_2,PACK_EMPTY);
        break;
        case 3:
        EEPROM.write(COUNTER_NUMBER_PACK_STATE_3,PACK_EMPTY);
        break;
        case 4:
         EEPROM.write(COUNTER_NUMBER_PACK_STATE_4,PACK_EMPTY);
        break;
        case 5:
         EEPROM.write(COUNTER_NUMBER_PACK_STATE_5,PACK_EMPTY);
        break;
        case 6:
         EEPROM.write(COUNTER_NUMBER_PACK_STATE_6,PACK_EMPTY);
        break;
        default :/*NOTHING ELSE*/;
        } 
        }
}
void search_car(uint8_t pack_selected)
{
  
  if(EEPROM.read(0x6E)!=pack_selected)
        {
          lcd.clear();
          lcd.setCursor(2,0);
          lcd.print("Car Found");
          while(1){
              motor_turn_on();
              if(Read_ir_sensor(IR_SENSOR_1)==1)
                {
                  car_counter++;
                  EEPROM.write(0x6e,car_counter);
                }
               
                if(car_counter==pack_selected)
                {
                  motor_stop();
                  break;
                }
                if(car_counter==7)
                {
                  car_counter=0;
                  EEPROM.write(0x6e,car_counter);

                }
          }
        }
        else if(car_counter==pack_selected)
              {
                lcd.clear();
              lcd.setCursor(0,0);
              lcd.print("PACK FOUND");
              delay(600);
              
              }
              
         
}
void welecom_user_interface(void){
   lcd.clear();
   lcd.setCursor(4,0);
   lcd.print("Welcome");
   lcd.setCursor(1,1);
   lcd.print("Parking Project");
   delay(4000);
}

/*-------------------------Selection---------------------------*/
void selection_interface(void){
  lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("1.New Car");
    lcd.setCursor(0,1);
   lcd.print("2.Return Car");
   
   while(1){
    if(digitalRead(0)==1)
      {
        Button_Flag=1;
        break;
      }
     else if(digitalRead(1)==1)
       {
          Button_Flag=2;
          break;
       }
   }
   switch(Button_Flag)
    {
      case 1:
      new_car_reg();
        break;
      case 2:
      return_car();
        break;
   }
   
}
/*-------------------------------------------Registeration-----------------------*/
void new_car_reg(void)
{
lcd.clear();
lcd.setCursor(2,0);
lcd.print("New Car");
lcd.setCursor(2,1);
lcd.print("IS Selected");
delay(500);
//check if the parking is empty
check_empty_pack();
//generate code search for car 
if(pack_state==PACK_EMPTY)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Enter Car No:");
    //Read car Number from User
      counter=0;
      while(1){
      if(counter==4)
       {
        break;
       }
        car_number[counter]=write_number_keypad();
        lcd.setCursor(2+counter,1);
        lcd.print(car_number[counter],DEC);
        delay(200);
        counter++;
 
}
lcd.clear();
lcd.setCursor(0,0);
lcd.print(empty_pack);

delay(500);
     switch(empty_pack)
       {
        case 1:
        lcd.print("1");
        delay(500);
        code_car_generate(PACK_ADD_1);
        search_car(empty_pack);
        break;
        case 2:
        code_car_generate(PACK_ADD_2);
        search_car(empty_pack);
        break;
        case 3:
        code_car_generate(PACK_ADD_3);
        search_car(empty_pack);
        break;
        case 4:
        code_car_generate(PACK_ADD_4);
        search_car(empty_pack);
        break;
        case 5:
        code_car_generate(PACK_ADD_5);
        search_car(empty_pack);
        break;
        case 6:
        code_car_generate(PACK_ADD_6);
        search_car(empty_pack);
        break;
        default :
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("MEMEORY INIT");
       lcd.setCursor(0,1);
       lcd.print("PLEASE");
       delay(500); 
       EEPROM.write(0x00,0);
       memory_init(); 
        }
        //EDIT PACK STATE IN MEMORY
        lcd.print("ghjgjhgj");
        delay(500);
         if(Read_ir_sensor(IR_SENSOR_2)!=1)
            {
               pack_states_edit(empty_pack,NEW_CAR);
            }
           
    }
    
    //if the parking is full
  else if(pack_state==PACK_FILL)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PARKING IS FULL");
      delay(4000);
    }
}

void code_car_generate(uint8_t pack_req){
  car_counter=EEPROM.read(COUNTER_PACK_ADD);
 for(counter=0;counter<4;counter++)
 {
 car_rand_code[counter]= EEPROM.read(counter+pack_req);
 }

 /*-----------------------GENERATING NEW CODE IN ARRAY BY USING CAR NUMBER--------------------------------*/
 counter_2=0;
  for(counter=0;counter<4;counter++)
 {
 car_rand_code[counter]=car_number[counter_2];
 counter_2++;
 }
 /*-----------------------SAVING NEW CODE IN EEPROM MEMORY--------------------------------*/
 for(counter=0;counter<4;counter++)
 {
EEPROM.write(counter+pack_req,car_rand_code[counter]);
 }
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("Your Code:");
  /*-----------------------DISPLAY NEW CODE TO USER--------------------------------*/
  counter_2=10;
 for(counter=0;counter<4;counter++)
 {
  lcd.setCursor(counter_2,0);
lcd.print(car_rand_code[counter],DEC);
counter_2++;
 }
 delay(4000);
}
/*------------------END FUNCTION-------------------------------------------------*/
void check_empty_pack(void)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("SEARCH EMPTY");
  lcd.setCursor(0,1);
  lcd.print("PACK. . . .");
  delay(500);
  //IF THE LAST PACK IS EMPTY 
  if(Read_ir_sensor(IR_SENSOR_2)!=1)
    {
      empty_pack=EEPROM.read(COUNTER_PACK_ADD);
    }
    //IF THE LAST PACK ISNOT EMPTY 
    else if(Read_ir_sensor(IR_SENSOR_2)==1)
    {
    for(counter=0;counter<6;counter++)
          {
          for(counter_2=0;counter_2<2;counter_2++)
          {
            
            if(counter_2==0) empty_pack = EEPROM.read(address_pack_states);
           if(counter_2==1) pack_state= EEPROM.read(address_pack_states+counter_2);
          }
          if(pack_state==PACK_EMPTY)break;
            address_pack_states+=2;
        }
    }
}
/*--------------------------END FUNCTION------------------------------------------------*/
/*-------------------------Return CAR---------------------------------------------------*/

void return_car(void){
uint8_t car_rand_code_temp[4];//Reading from User 
uint8_t flag=0;
uint8_t temp_intex_counter=0;
 lcd.clear();
lcd.setCursor(2,0);
lcd.print("RETURN CAR");
lcd.setCursor(2,1);
lcd.print("IS Selected");
delay(500);
 lcd.clear();
lcd.setCursor(0,0);
lcd.print("write your code:");
//Reading CODE from User
for(counter=0;counter<4;counter++)
{
 
 car_rand_code_temp[counter]= write_number_keypad();
 lcd.setCursor(0+counter,1);
 lcd.print(car_rand_code_temp[counter]);
 delay(130);
}
//Reading from code in memory
    for(counter=0;counter<6;counter++)
        {
          for(counter_2=0;counter_2<4;counter_2++)
          {
            car_rand_code[counter_2]=EEPROM.read(address_rand_code+counter_2);
          }
           //check if Number equal user entered 
           for(counter_2=0;counter_2<4;counter_2++)
          {
            if(car_rand_code[counter_2]==car_rand_code_temp[counter_2])
            {
              flag=1;
            }
            else{
              flag=0;
              break;
            }
          }
          //if equal to user number go out from loop
          if(flag==1)break;
          address_rand_code+=4;
          temp_intex_counter++;
        } 
           delay(500);
            lcd.clear();
           lcd.setCursor(0,0);
           lcd.print("Search . . .");
           delay(500);
       
        if(flag==1)//FOUND
          {
            lcd.print(temp_intex_counter);
            delay(350);
            search_car((temp_intex_counter));
            if(Read_ir_sensor(IR_SENSOR_2)==0)
            {
               pack_states_edit(temp_intex_counter,RETURN_CAR);
            }
          }
         else if(flag==0){//NOT FOUND
           lcd.clear();
           lcd.setCursor(0,0);
           lcd.print("Sorry Code");
           lcd.setCursor(0,1);
           lcd.print("Not Found");
           delay(4000);
         }
}
