// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 3
// Exercise 1
// Submission code: 482740 (provided by your TA-s)

#define BLINK_PIN 13 //defining pin number for led
#define BUTTLED_PIN 12 //defining pin number for led
#define BUTTON_PIN 7 //defining pin number for button

int ON = HIGH; // storing the HIGH value
int OFF = LOW; // storing the LOW value

void setup(){ 
  pinMode(BLINK_PIN, OUTPUT); // initializing pin as output
  pinMode(BUTTLED_PIN, OUTPUT); // initializing pin as output
  pinMode(BUTTON_PIN, INPUT); // initializing pin as input
}

void loop(){
  
  if (digitalRead(BUTTON_PIN) == ON) { // checking if the button is pressed
    digitalWrite(BUTTLED_PIN, ON); // turning the led ON
  }
  else {
    digitalWrite(BUTTLED_PIN, OFF); // turning the led off
  }

  /*This led turns on and off with a delay of 1 second*/
  digitalWrite(BLINK_PIN, ON); // turning led on
  delay(1000); // delay 1 second
  digitalWrite(BLINK_PIN, OFF); // turing led off
  delay(1000); // delay 1 second
  

}


