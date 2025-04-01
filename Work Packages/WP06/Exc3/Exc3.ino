// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 6
// Exercise 3
// Submission code: 110306 (provided by your TA-s)

#include <Adafruit_NeoPixel.h>// include library for Neopixel

#include <Keypad.h> // include library for keypad

#define LISTOFROWPINS {11, 10, 9, 8} // list that contain no of row pins
#define LISTOFCOLPINS {7, 6, 5, 4} // list that contain no of col pins

#define NO_OF_LEDS 24 // no of LEDs

#define NEOPIXEL_PIN 2 // the neopixel pin

#define numOfRows 4 // num of rows in keypad
#define numOfCols 4 // num of cols in keypad

#define numOfStrings 8 // num of strings in the list of stargate addresses
#define CHAR_MAX 7 // max no of char in a stargate address string

byte rowPins[] = LISTOFROWPINS; // make list of row pins as byte
byte colPins[] = LISTOFCOLPINS; // make list of col pins as byte

// list of char keys in keypad
char listOfKeys[numOfRows][numOfCols] = {{'1','2','3','A'},
										                     {'4','5','6','B'},
                          		       	   {'7','8','9','C'},
                         		       	     {'*','0','#','D'}};

// list of stargate addresses                                     
String listOfAddresses[numOfStrings] = {"1AC91BD", "342824A", "6D1732B", "52A64AC", "413553A", "34246CC", "23B393B", "9999999"};

// initalize keypad object
Keypad keypad = Keypad(makeKeymap(listOfKeys), rowPins, colPins, numOfRows, numOfCols);

// initalize neopixel ring object
Adafruit_NeoPixel ring(NO_OF_LEDS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

// userInputString from keypad
String userInputString;

// to check if address is equal to any of the stargate addresses in the list
bool addressEqualToList = false;

uint32_t redColor = ring.Color(255, 0, 0); // redColor in unsigned int 32bit format
uint32_t greenColor = ring.Color(0, 255, 0); // greenColor in unsigned int 32bit format
uint32_t blueColor = ring.Color(0, 0, 255); // blueColor in unsigned int 32bit format

// setup for the stargate program
void setup() {
  
  Serial.begin(9600); // start arduino communication to use serial.print
  
  ring.begin(); // start the ring communincation 
  ring.show(); // empty the neopixel pixels data by doing .show
  
}

// loop for the stargate program
void loop() {
    
  // for each character in the string
  for(int i = 0; i < CHAR_MAX; i++){
    userInputString += keypad.waitForKey(); // wait for user input, must input 7 character as char_MAX is 7
  }
  
  Serial.print("Stargate address: "); // print stargate address template
  Serial.println(userInputString); // print the stargate address
   
  // for each string in the list of stargate addresses
  for(int i = 0; i < numOfStrings; i++){
    if(listOfAddresses[i].equals(userInputString) == true){ // if the string equals to the user inputted string
      addressEqualToList = true; // set to true
    }
    // otherwise stay false/do nothing
  }
  
  // for each character in the user inputted string
  for(int i = 0; i < CHAR_MAX; i++){
    switchBetweenColors(); // switchh between colors
    lockColors(i); // lock colors for that character index
  }
  
  userInputString = ""; // set the user input string to empty, if user want to try again
}

// switches between colors to show that the gate is dialing, 
// the animation is that the neopixel will change colors every second for 3 seconds
void switchBetweenColors(){
    ring.fill(greenColor, 0, NO_OF_LEDS); // fill all pixels with green color
    ring.show(); // show the green colored pixels
    delay(1000); // show for a second
    ring.clear(); // clear the pixels
    ring.fill(redColor, 0, NO_OF_LEDS); // fill all pixels with red color
    ring.show();  // show the red colored pixels
    delay(1000); // show for a second
    ring.clear(); // clear the pixels
    ring.fill(blueColor, 0, NO_OF_LEDS); // fill all pixels with blue color
    ring.show(); // show the blue colored pixels
    delay(1000); // show for a second
    ring.clear(); // clear the pixels
}

// lock the colors for each character in the string,
// locks using the green color for 3 seconds
// for the last character, it checks if the boolean was true to continue otherwise it will 
// show an error animation where it will blink red color
void lockColors(int i) { // takes in the character index
    switch(i) { // for each char index
      case 0: // for the first characters
        ring.fill(greenColor, 20, 2); // fils the pixel 20 and 21 with green color based on specification
        ring.show(); // show the pixels
        delay(3000); // show for 3 seconds
        ring.clear(); // clear the pixels
        break; // break to get out of the switch case and not trigger other cases

      case 1: // for the second character
        ring.fill(greenColor, 20, 2); // fills the pixels 20 and 21 for the first character
        ring.setPixelColor(23, greenColor); // fills the first pixel for second char
        ring.setPixelColor(0, greenColor); // fills the second pixel for second char
        ring.show(); // show the pixels
        delay(3000); // show for 3 seconds
        ring.clear(); // clear the pixels
        break;  // break to get out of the switch case and not trigger other cases

      case 2: // for the third character 
        ring.fill(greenColor, 20, 2); // fills the pixel 20 and 21 for the first character
        ring.setPixelColor(23, greenColor); // fills the first pixel for second char
        ring.setPixelColor(0, greenColor); // fills the second pixel for second char
        ring.fill(greenColor, 2, 2); // fills the pixel 2 and 3 for the third char
        ring.show(); // show the pixels
        delay(3000); // show the pixels for 3 sec
        ring.clear(); // clear the pixels
        break; // break to get out of the switch case and not trigger other cases

      case 3: // for the fourth character
        ring.fill(greenColor, 20, 2); // fills the pixel 20 and 21 for the first character
        ring.setPixelColor(23, greenColor); // fills the first pixel for second char
        ring.setPixelColor(0, greenColor); // fills the second pixel for second char
        ring.fill(greenColor, 2, 2); // fills the pixel 2 and 3 for the third char
        ring.fill(greenColor, 8, 2); // fills the pixel 8 and 9 for the fourth char
        ring.show(); // show the pixels
        delay(3000); // show the pixels for 3 sec
        ring.clear(); // clear the pixels
        break; // break to get out of the switch case and not trigger other cases

      case 4: // for the fifth character
        ring.fill(greenColor, 20, 2); // fills the pixel 20 and 21 for the first character
        ring.setPixelColor(23, greenColor); // fills the first pixel for second char
        ring.setPixelColor(0, greenColor); // fills the second pixel for second char
        ring.fill(greenColor, 2, 2); // fills the pixel 2 and 3 for the third char
        ring.fill(greenColor, 8, 2); // fills the pixel 8 and 9 for the fourth char
        ring.fill(greenColor, 11, 2); // fills the pixel 11 and 12 for the fifth char
        ring.show(); // show the pixels
        delay(3000); // show the pixels for 3 sec
        ring.clear(); // clear the pixels
        break; // break to get out of the switch case and not trigger other cases

      case 5: // for the sixth character
        ring.fill(greenColor, 20, 2); // fills the pixel 20 and 21 for the first character
        ring.setPixelColor(23, greenColor); // fills the first pixel for second char
        ring.setPixelColor(0, greenColor); // fills the second pixel for second char
        ring.fill(greenColor, 2, 2); // fills the pixel 2 and 3 for the third char
        ring.fill(greenColor, 8, 2); // fills the pixel 8 and 9 for the fourth char
        ring.fill(greenColor, 11, 2); // fills the pixel 11 and 12 for the fifth char 
        ring.fill(greenColor, 14, 2);  // fills the pixel 14 and 15 for the sixth char
        ring.show(); // show the pixels
        delay(3000); // show the pixels for 3 sec
        ring.clear(); // clear the pixels
        break; // break to get out of the switch case and not trigger other cases

      case 6: // for the seventh character
      	if(!addressEqualToList){ // if the string doesnt equal to a stargate address
          int z = 0; // index loop to show red blinking for 6 seconds
          while(z < 6){ // while index is less than 6 seconds
            ring.fill(redColor, 0, NO_OF_LEDS); // fill all pixels with red color
            ring.show(); // show the pixels
            delay(500); // show for half a seconds
            ring.clear(); // clear the pixels
            ring.show(); // show the cleared pixels
            delay(500); // show the cleared pixels for half a second
            z++; // increment index loop by 1
          }
      	} else {
          ring.fill(greenColor, 20, 2); // fills the pixel 20 and 21 for the first character
          ring.setPixelColor(23, greenColor); // fills the first pixel for second char
          ring.setPixelColor(0, greenColor); // fills the second pixel for second char
          ring.fill(greenColor, 2, 2); // fills the pixel 2 and 3 for the third char
          ring.fill(greenColor, 8, 2); // fills the pixel 8 and 9 for the fourth char
          ring.fill(greenColor, 11, 2); // fills the pixel 11 and 12 for the fifth char 
          ring.fill(greenColor, 14, 2);  // fills the pixel 14 and 15 for the sixth char
      	  ring.fill(greenColor, 17, 2); // fills the pixel 17 and 18 for the seventh char
          ring.show(); // show the pixels
          delay(3000); // show the pixels for 3 sec
          ring.clear(); // clear the pixels
          break; // break to get out of the switch case and not trigger other cases
      	}
    }
  }