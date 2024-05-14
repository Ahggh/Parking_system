#ifndef PARKING_MEM
#define PARKING_MEM
#include <EEPROM.h>

#define COUNTER_PACK_OPERATION                      0//FROM SENSOR 1
#define COUNTER_PACK_ADD                           0X6E //FROM SENSOR 1
 /*-------------------------------------------------------------*/
#define COUNTER_NUMBER_PACK_STATE_OPERATION     1 
#define COUNTER_NUMBER_PACK_STATE_FIRST_ADD    0X62 
#define COUNTER_NUMBER_PACK_STATE_END_ADD      0X6D
#define COUNTER_NUMBER_PACK_STATE_1                  0X63
#define COUNTER_NUMBER_PACK_STATE_2                  0X65
#define COUNTER_NUMBER_PACK_STATE_3                  0X67
#define COUNTER_NUMBER_PACK_STATE_4                  0X69
#define COUNTER_NUMBER_PACK_STATE_5                  0X6B
#define COUNTER_NUMBER_PACK_STATE_6                  0X6D

 /*-------------------------------------------------------------*/
#define PACK_CODES_OPERATION               2
#define PACK_CODES_FIRST_ADD                   0X01 
#define PACK_CODES_END_ADD                     0X60
#define PACK_ADD_1                              0X01
#define PACK_ADD_2                              0X0B
#define PACK_ADD_3                              0X15
#define PACK_ADD_4                              0X1F
#define PACK_ADD_5                              0X0A
#define PACK_ADD_6                              0X29
 /*-------------------------------------------------------------*/
//FROM SENSOR 2
#define GENERAL_PARKING_STATE                   3
#define PACK_FILL                               1
#define PACK_EMPTY                              0

uint8_t car_counter;

unsigned short  address_rand_code=PACK_CODES_FIRST_ADD;
unsigned short  address_pack_states=COUNTER_NUMBER_PACK_STATE_FIRST_ADD;
#endif
