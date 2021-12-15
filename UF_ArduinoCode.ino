#include <Keypad.h> // porting the Keypad library so its functions can be called in the program

// define the number of columns and rows
const int ROW_NUM = 8; // set 8 rows
const int COLUMN_NUM = 11; // set 11 columns

// create a two-dimensional array of rows and columns
// assign an integer value for each coordinate of the matrix
// these correspond to the MIDI values for the 88 keys of the keyboard
const char keys[ROW_NUM][COLUMN_NUM]={
  { 21 , 22  ,  23  , 24  ,  25  ,  26  ,  27  ,  28  ,  29  ,  30  },
  { 32 ,  33 ,  34  , 35  ,  36  ,  37  ,  38  ,  39  ,  40  ,  41  },
  { 43 ,  44 ,  45  , 46  ,  47  ,  48  ,  49  ,  50  ,  51  ,  52  },
  { 54 ,  55 ,  56  , 57  ,  58  ,  59  ,  60  ,  61  ,  62  ,  63  },
  { 65 ,  66 ,  67  , 68  ,  69  ,  70  ,  71  ,  72  ,  73  ,  74  },
  { 76 ,  77 ,  78  , 79  ,  80  ,  81  ,  82  ,  83  ,  84  ,  85  },
  { 87 ,  88 ,  89  , 90  ,  91  ,  92  ,  93  ,  94  ,  95  ,  96  },
  { 98 ,  99 ,  100 , 101 ,  102 ,  103 ,  104 ,  105 ,  106 ,  107 },
};

// connect the rows/columns to their relevant GPIO pins
byte pin_rows[ROW_NUM] = {2, 3, 4, 5, 6, 7, 8, 9}; // connect to the row pinouts of the keypad
byte pin_column[COLUMN_NUM] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32}; // connect to the column pinouts of the keypad

// instantiate a new Keypad object using the Keypad library
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

// initialise the serial port and rate
void setup(){
  Serial.begin(9600);
}

// continuously check for key presses = pin activity
// print any keypress results to the serial monitor
void loop(){
  int key = keypad.getKey();

  if (key){
    Serial.println(key);
  }
}
