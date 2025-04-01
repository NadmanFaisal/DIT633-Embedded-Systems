// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 6
// Exercise 2
// Submission code: 110306 (provided by your TA-s)


//#############SLAVE ARDUINO##################

#define TRIG_PIN 7
#define ECHO_PIN 8

// Defined distances 
#define DISTANCE_5 200
#define DISTANCE_4 150
#define DISTANCE_3 75
#define DISTANCE_2 30
#define DISTANCE_1 25

/* setup program */
void setup() {
  Serial.begin(9600);  // start serial communication with arduino
}

/* loop program */
void loop() {
  int cm; // set cm variable to int
     
  cm = getCentimeters(); // get centimeters
  Serial.println(cm); // send it in serial so that serial port pin picks it up and sends it to the other arduino
  delay(100); // delay for 100ms
}

int getCentimeters() {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  pinMode(TRIG_PIN, OUTPUT); // read trigger pin as output to send signals
  
  digitalWrite(TRIG_PIN, LOW); // set trigger pin to LOW
  delayMicroseconds(2); // delay for 2 microseconds
  digitalWrite(TRIG_PIN, HIGH); // set trigger pin to HIGH, read value
  delayMicroseconds(5); // delay for5 microseconds
  digitalWrite(TRIG_PIN, LOW); // set trig pin to LOW
  
  pinMode(ECHO_PIN, INPUT); // set echo pin to input to read echoes
  int duration = pulseIn(ECHO_PIN, HIGH); // calculate duration it took to read the echo using PulseIn func
  
  return duration / 29 / 2; // return it by dividing by 29 microseconds and then 2 since it travels back and forth
}
