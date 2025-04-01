// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 6
// Exercise 1
// Submission code: 110306 (provided by your TA-s)

#define TRIG_PIN 7                // Pin defined for triggering signal for radar sensor
#define ECHO_PIN 8                // Pin defined to read echo signal for radar sensor

// Pins defined for the LEDs
#define LED_1 5
#define LED_2 4
#define LED_3 3
#define LED_4 2

#define PIEZO_PIN 9               // Pin defined for the Piezo sensor (buzzer)

// Distances defined for parking system
#define DISTANCE_5 200
#define DISTANCE_4 150
#define DISTANCE_3 75
#define DISTANCE_2 30
#define DISTANCE_1 25

bool lightFlag = false;           // Boolean to indicate when to turn the lights on or off

void setup() {
  Serial.begin(9600);             // Initializes serial with 9600 baud
  setupTimer1();                  // Sets up timer1
  pinMode(PIEZO_PIN, OUTPUT);     // Sets PIEZO pin to OUTPUT
  pinMode(LED_1, OUTPUT);         // Initializes LED_1 as output
  pinMode(LED_2, OUTPUT);         // Initializes LED_2 as output
  pinMode(LED_3, OUTPUT);         // Initializes LED_3 as output
  pinMode(LED_4, OUTPUT);         // Initializes LED_4 as output
}

void loop() {
  long cm;                                // Variable to hold the calculated distance in centimeters
   
  turnOffLED(4);                          // Turns off all the LEDs
  
  cm = getCentimeters();                  // Returns distance in centimeters and stores in variable
  
  if(cm < DISTANCE_1) {                   // If the calculated distance is less than the defined distance, 
    if(lightFlag) turnOnLED(4);           // and if light flag is true, turns on all LEDs, 
    else turnOffLED(4);                   // else turns the LEDs off, mimicing blinking. 
    turnOnSound(cm);                      // Makes the buzzer buzz
  } else if(cm < DISTANCE_2) {            // If the calculated distance is less than the second defined distance, 
    turnOnLED(4);                         // Turns on all LEDs, 
    turnOnSound(cm);                      // and makes the buzzer buss
  } else if(cm < DISTANCE_3) {            // If the calculated distance is less than the third defined distance, 
  	turnOnLED(3);                         // turns on only 3 LEDs, 
    turnOnSound(cm);                      // and makes the buzzer buss
  } else if(cm < DISTANCE_4) {            // If the calculated distance is less than the fourth defined distance, 
    turnOnLED(2);                         // turns on only 2 LEDs, 
    turnOnSound(cm);                      // and makes the buzzer buss
  } else if(cm < DISTANCE_5) {            // If the calculated distance is less than the fourth defined distance, 
  	turnOnLED(1);                         // turns on only 1 LEDs, 
    turnOnSound(cm);                      // and makes the buzzer buss
  } else {                                // else, 
    turnOffLED(4);                        // turns off all the LEDs, 
    turnOnSound(cm);                      // sounds according to the calculated distance
  }
  
  delay(100);
}

long getCentimeters() {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  pinMode(TRIG_PIN, OUTPUT);              // Sets the trigger pin to output to send pings from the radar sensor
  
  digitalWrite(TRIG_PIN, LOW);            // Sets the trigger pin to LOW to clear any previous incoming pings
  delayMicroseconds(2);                   // Waits for 2 us to clear incoming pings
  digitalWrite(TRIG_PIN, HIGH);           // Sends a ping, 
  delayMicroseconds(5);                   // Waits for 5 us
  digitalWrite(TRIG_PIN, LOW);            // Switches off sending pings
  
  pinMode(ECHO_PIN, INPUT);               // The echo pin receives the ping, so set to input
  long duration = pulseIn(ECHO_PIN, HIGH);// Calculates the duration of the ping
  
  return duration / 29 / 2;               // Converts microseconds to seconds and then divides by 2 as the pings travel twice (bounces off
                                          // a surface and comes back).
}

/*
Turns on the LEDs according to the value of the parameters
*/
void turnOnLED(int num) {
  int pins[] = {LED_1, LED_2, LED_3, LED_4};        // List of all the LED pins
  for(int i = 0; i < num; i++) {                    // Loops through the list and 
    digitalWrite(pins[i], HIGH);                    // Sets them to HIGH
  }
}

/*
Turns off the LEDs according to the value of the parameters
*/
void turnOffLED(int num) {
  int pins[] = {LED_1, LED_2, LED_3, LED_4};        // List of all the LED pins
  for(int i = 0; i < num; i++) {                    // Loops through the list and 
    digitalWrite(pins[i], LOW);                     // Sets them to LOW
  }
}

/*
Turns on the sound of the PIEZO according to the distance 
provided as the parameter
*/
void turnOnSound(int distance) {
  if(distance < DISTANCE_1) {             // If the distance is lower than the defined distance, 
    digitalWrite(PIEZO_PIN, HIGH);        // Turns on the piezo, 
    tone(PIEZO_PIN, 1000, 100);           // and makes a high pitched sound.
  } else if(distance < DISTANCE_2) {      // If the distance is lower than the defined distance, 
    digitalWrite(PIEZO_PIN, HIGH);        // Turns on the piezo and 
    tone(PIEZO_PIN, 800, 100);            // Makes a lower high pitched sound
  } else if(distance < DISTANCE_3) {      // If the distance is lower then the defined distance, 
    digitalWrite(PIEZO_PIN, HIGH);        // Turns on the piezo and 
  	tone(PIEZO_PIN, 600, 100);            // Makes a high pitched sound
  } else if(distance < DISTANCE_4) {      // If the distance is lower then the defined distance, 
    digitalWrite(PIEZO_PIN, HIGH);        // Turns on the piezo and 
    tone(PIEZO_PIN, 400, 100);            // Makes a low pitched sound
  } else if(distance < DISTANCE_5) {      // If the distance is lower then the defined distance, 
    digitalWrite(PIEZO_PIN, HIGH);        // Turns on the piezo and 
  	tone(PIEZO_PIN, 200, 100);            // Makes an even lower pitched sound
  } else {                                // Else, 
    digitalWrite(PIEZO_PIN, LOW);         // turns off the piezo
  }
}

// Sets up the timer1, source: https://www.instructables.com/Arduino-Timer-Interrupts/
void setupTimer1(){
  cli();
  TCCR1A = 0;       // set entire TCCR1A register to 0
  TCCR1B = 0;       // same for TCCR1B
  TCNT1  = 0;       //initialize counter value to 0
  // set compare match register for 1hz increments
  OCR1A = 15624;// = (16*10^6) / (1*1024) - 1 (must be <65536)
  // turn on CTC mode
  TCCR1B |= (1 << WGM12);
  // Set CS10 and CS12 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);
  sei();//allow interrupts

}//end setup

// ISR method to switch lightflag boolean value
ISR(TIMER1_COMPA_vect){
  lightFlag = !lightFlag;           // If the lightFlag is true, turns it to false. If false, turns it
                                    // to true.
}