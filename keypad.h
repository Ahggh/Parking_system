
#define KEYPAD_ROW_1  3
#define KEYPAD_ROW_2  4
#define KEYPAD_ROW_3  5
#define KEYPAD_ROW_4  6

#define KEYPAD_COLUMN_1  7
#define KEYPAD_COLUMN_2  8
#define KEYPAD_COLUMN_3  9

uint8_t keypad_rows[]={KEYPAD_ROW_1,KEYPAD_ROW_2,KEYPAD_ROW_3,KEYPAD_ROW_4};
uint8_t keypad_coulmn[]={KEYPAD_COLUMN_1,KEYPAD_COLUMN_2,KEYPAD_COLUMN_3};
uint8_t keypad_values[4][3]={{1,2,3},{4,5,6},{7,8,9},{0,0,0}};

uint8_t row_counter=0;
uint8_t column_counter=0;
