// Based on the following tutorial: https://www.instructables.com/Arduino-Timer-Interrupts/

// Defined pins for the LEDs
#define LED_1 9
#define LED_2 10
#define LED_3 11
#define LED_4 12
#define LED_5 13

#define TEMP_PIN A0

// Defined ranges for temperature
#define RANGE_1 10
#define RANGE_2 20
#define RANGE_3 30
#define RANGE_4 40

float temp;             // Global variable to hold temp value

// Define data rate for Serial
#define DATA_RATE 9600

// The following definitions is used for the calculation of timer frequency in setup_timer_1 function
#define PRESCALER 1024          // used for dictating speed of timer according to (timer speed (Hz)) = (Arduino clock speed (16MHz)) / prescaler
#define INTERRUPT_FREQ 1        // define interrupt frequency
#define CLOCK_SPEED 16000000    // Clock speed of the Arduino Uno
#define TIMER1_MAX 65535        // Max counter value for timer1
#define TIMER1_LOW 257          // Lowest counter value for timer1
#define TIME_PERIOD 1		        // The time interval after which the interrupt is triggered

int iCounter = 0;               // Variable to keep track of times interrupt is triggered

void setup()
{
  setup_timer_1();              // Setup timer1 from timer1 library
  Serial.begin(DATA_RATE);      // Initializes the Serial monitor

  pinMode(LED_1, OUTPUT);       // LED_1 initialized as output to show light
  pinMode(LED_2, OUTPUT);       // LED_2 initialized as output to show light
  pinMode(LED_3, OUTPUT);       // LED_3 initialized as output to show light
  pinMode(LED_4, OUTPUT);       // LED_4 initialized as output to show light
  pinMode(LED_5, OUTPUT);       // LED_5 initialized as output to show light
    
}

void loop()
{
  
  digitalWrite(LED_1, LOW);       // Turns off LED_1
  digitalWrite(LED_2, LOW);       // Turns off LED_2
  digitalWrite(LED_3, LOW);       // Turns off LED_3
  digitalWrite(LED_4, LOW);       // Turns off LED_4
  digitalWrite(LED_5, LOW);       // Turns off LED_5
  
  if(temp <= RANGE_1) {           // If temperature less than the first defined range, 
    digitalWrite(LED_1, HIGH);    // turns on LED_1
  } else if(temp <= RANGE_2) {    // If temperature less than the second defined range, 
    digitalWrite(LED_1, HIGH);    // turns of LED_1 and
    digitalWrite(LED_2, HIGH);    // LED_2
  } else if(temp <= RANGE_3) {    // If temperature less than the third defined range, 
    digitalWrite(LED_1, HIGH);    // turns on LED_1,
    digitalWrite(LED_2, HIGH);    // turns on LED_2, and 
    digitalWrite(LED_3, HIGH);    // turns on LED_3
  } else if(temp <= RANGE_4) {    // If temperature less than fourth defined range, 
    digitalWrite(LED_1, HIGH);    // turns on LED_1, 
    digitalWrite(LED_2, HIGH);    // turns on LED_2,
    digitalWrite(LED_3, HIGH);    // turns on LED_3, and 
    digitalWrite(LED_4, HIGH);    // turns on LED_4
  } else {                        // If temperature is outside of those ranges, 
                                  // turns on all the LEDs.
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
    digitalWrite(LED_5, HIGH);
  }
  
}

/* 
This method is responsible for setting the global temp variable 
to the value which is read from the analog pin from the 
temperature sensor.
*/
void setTemp(){
  float reading = analogRead(TEMP_PIN);       // Analog readings taken from the temp sensor
  float voltage = (float)reading * 5.0;       // Reading converted from mili amps to voltage
  voltage /= 1024.0;                          // Converts millivolt to volts
  temp = (voltage - 0.5) * 100;               // Converts volt to temo
  Serial.print(temp);                         // Prints the temp in the serial monitor
  Serial.print("\n");
}

/* 
This function sets up timer1 on an Arduino Uno
Sets timer1 interrupt at 1Hz = 1 second = 1 cycle per second
*/
void setup_timer_1() {

  cli();        // Stops the interrupts

  TCCR1A = 0;   // Clears TCCR1A register
  TCCR1B = 0;	  // Clears TCCR1B register
  TCNT1 = 0; 	  // Initialize counter value to 0

  // Calculate at which point to stop the counter and set to int:
  timer1 = (CLOCK_SPEED / (PRESCALER / TIME_PERIOD)) - 1;		// Frequency = 1/TIME_PERIOD
  
  if (timer1 >= TIMER1_MAX) {                                                         // if value went above max value
    timer1 = TIMER1_MAX;                                                             // set timer to max allowed value
    Serial.println((String) "timer1 was set too high and was changed to: " + timer1);// notify user
   } else if (timer1 <= TIMER1_LOW) {                                                  // if value went below lowest value
    timer1 = TIMER1_LOW;                                                             // set timer to max allowed value
    Serial.println((String) "timer1 was set too low and was changed to: " + timer1); // notify user
  }

  OCR1A = timer1;                     // Set compare match register for 1hz increments
  TCCR1B |= (1 << WGM12);             // Turns on the CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10);// Sets CS10 and CS12 bits for 1024 prescaler
  TIMSK1 |= (1 << OCIE1A);            // Enables the timer compare interrupt

  sei();          //allow interrupts
}

/*
According to the setup_timer_1, interrupts gets 
triggered every 1 second (1Hz).
*/
ISR(TIMER1_COMPA_vect) {
  cli();                            // stop interrupts
  Serial.print("Timer i: ");
  Serial.println(iCounter);         // Prints iCounter in the serial monitor
  setTemp();                        // Calls the setTemp method to calculate temp value
  iCounter++;                       // Increments iCounter to indicate time
  sei();                            // allow interrupts
}