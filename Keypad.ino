#include "keypad.h"
void pins_keypad_setup(void){
  //row
  for(counter=0;counter<4;counter++)
    {
       pinMode(keypad_rows[counter],OUTPUT);
    }
    //coulmn
    for(counter=0;counter<3;counter++)
    {
       pinMode(keypad_coulmn[counter],INPUT);
    }
}

uint8_t write_number_keypad(void){
 uint8_t read_keypad;
 Button_Flag=0;
  while(1)
    {
      for(row_counter=0;row_counter<4;row_counter++)
        {
          digitalWrite(keypad_rows[row_counter],HIGH);
          for(column_counter=0;column_counter<3;column_counter++)
            {
              if(digitalRead(keypad_coulmn[column_counter])==1)
                {
                 read_keypad =keypad_values[row_counter][column_counter];
                 Button_Flag=1;
                 break;
                }
                
            }
            digitalWrite(keypad_rows[row_counter],LOW);
            
             //end_column_loop
        }
        if(Button_Flag==1)
          {
            break;
          }
        //end_row_loop
    }
    //end_while_loop
   return read_keypad;
}
