// Based on the following tutorial: https://www.instructables.com/Arduino-Timer-Interrupts/

#include <Servo.h>        // Servo library for the Servo actuator

int signalPin1 = 5;           // Pin used to attach to signal in Servo actuator
int signalPin2 = 6;           // Pin used to attach to signal in Servo actuator
int iCounter = 0;             // Variable to keep track of times interrupt is triggered
int timer2 = 0;               // Variable to store time speed
int second = 0;               // Variable to keep track of seconds
int minute = 0;               // Variable to keep track of minutes
bool flag = false;            // Flag used to print 'time' in serial monitor

Servo secondServo;            // Initializes Servo actuator for seconds
Servo minuteServo;            // Initializes Servo actuator for minutes

void setup() {
  setup_timer_2();                    // Initializes timer2 from timer2 library
  Serial.begin(9600);                 // Initializes the serial monitor
  secondServo.attach(signalPin1);     // Attaches the servo actuator to the signalPin
  minuteServo.attach(signalPin2);     // Attaches the servo actuator to the signalPin
}

void loop() {
  if(flag) {                        // If the flag is set to true, 
    flag = false;                   // turns it to false and 
    Serial.print("seconds: ");      // Prints the prompt for seconds 
    Serial.print(second);           // prints the time in the monitor
    Serial.print("\n");
    Serial.print("minutes: ");      // Prints the prompt for minutes
    Serial.print(minute);           // Prints the minute
    Serial.print("\n");
  }
  secondServo.write(second * 3);    // Moves the seconds servo actuator (180 degrees divided by 60 is 3).
  minuteServo.write(minute * 3);    // Moves the minutes servo actuator (180 degrees divided by 60 is 3).
}

// Timer2 interrupts every 128us
void setup_timer_2() {
  cli();        // Stops the interrupts
  
  TCCR2A = 0;           // Sets the TCCR2A register to 0
  TCCR2B = 0;           // Sets the TCCR2B register to 0
  TCNT2  = 0;           // Initializes the counter value to 0
  timer2 = 255;         // set compare match register for 7.8khz increments
  OCR2A = timer2;       // Sets OCR2A to timer2 value

  TCCR2A |= (1 << WGM21);         // Turns on CTC mode
  TCCR2B |= (1 << CS21);          // Sets the CS21 bit for 8 prescaler
  TIMSK2 |= (1 << OCIE2A);        // enable timer compare interrupt
  
  sei();        // Allows interrupts
}

/*
According to the setup_timer_2, interrupts gets 
triggered every 128 micro-seconds (7.8kHz).
*/
ISR(TIMER2_COMPA_vect) { 
  iCounter++;                               // Increments the counter
  if(iCounter > 7812) {                     // iCounter being greater than 7812 means 1 second has passed.
    iCounter = 0;                           // Sets the counter back to 0
    second = (second + 1) % 60;             // Second increments
    flag = true;                            // Sets the flag to true for printing in serial monitor
    if(second == 0) {                       // If seconds equal to 0, indicates a minute has passed, 
      minute = (minute + 1) % 60;           // Increment minute
    }
  }
}  
