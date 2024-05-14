#include "Ir_sensor.h"

/*-----------------Setup_pins_ir------------------------------*/
void pins_ir_sensor(void){
   pinMode(ir_sensor[0],INPUT);
   pinMode(ir_sensor[1],INPUT);
}
/*-----------------Reading_sesnor------------------------------*/
uint8_t Read_ir_sensor(uint8_t ir_sensor_select){
  uint8_t sensor_read;
  switch(ir_sensor_select)
    {
      case IR_SENSOR_1:
        ir_sensor_select=!digitalRead(IR_SENSOR_1);
        break;
      case IR_SENSOR_2:
       ir_sensor_select=!digitalRead(IR_SENSOR_2);
        break;
       default:/*Nothing Else*/;
    }
    return ir_sensor_select;
}
