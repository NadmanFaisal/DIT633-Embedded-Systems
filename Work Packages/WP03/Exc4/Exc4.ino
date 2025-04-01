// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 3
// Exercise 4
// Submission code: 482740 (provided by your TA-s)

#include <Keypad.h>               // Keypad library

const byte ROWS = 4;              // 4 bytes for 4 rows
const byte COLS = 4;              // 4 bytes for 4 columns

// 2D array representing the keypad values
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'F', '0', 'E', 'D'},
};

byte rowPins[ROWS] = {11, 10, 9, 8};      // The pins for the rows
byte colPins[COLS] = {7, 6, 5, 4};        // The pins for the columns

Keypad keypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);        // Configures the rows and cols pins to the Keypad

void setup(){
  Serial.begin(9600);             // Initializes the serial to print the characters
}

void loop(){
  char key = keypad.getKey();     // Returns the value of the key that is pressed
  
  if (key) {                      // If there is a key that has been returned
    Serial.println(key);          // Prints the key on the serial
  }
  
  delay(1000);                    // Delay for 1 second
}