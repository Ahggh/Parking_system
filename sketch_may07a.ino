#include "general_Initialization.h"
#include "Ir_sensor.h"

void setup() {
  lcd.begin(16,2);
 pin_selection_setup();
 motor_setup_pins();

 pins_keypad_setup();
 pins_ir_sensor(); 
// welecom_user_interface();
  if(EEPROM.read(0x00)==1)
    {
      lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("SEL MEMORY INIT?");
    lcd.setCursor(0,1);
   lcd.print("1.YES");
   lcd.setCursor(12,1);
   lcd.print("2.NO");
   while(1)
   {
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
      EEPROM.write(0x00,0);
       memory_init();
        break; 
   }
      
    }
    else{
       memory_init();
    }



}

void loop() {
//go to options(NEW_CAR RETURN_CAR)

delay(100);
selection_interface();

}
