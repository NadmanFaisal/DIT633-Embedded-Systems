#include <Adafruit_NeoPixel.h>        // Neopixel ring library

#define RING_PIN 3                    // Pin which is attached to the ring
#define TEMP_PIN A0                   // Analog pin used to read temperature
#define LED_COUNT 12                  // Number of LEDs in the ring
#define LED_PIN 11                    // Pin for the red LED
#define ORANGE 255, 165, 0            // Values representing ORANGE color

// Initializes the Neopixel ring as 'strip'
Adafruit_NeoPixel strip(LED_COUNT, RING_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);           // Initializes the serial monitor
  pinMode(LED_PIN, OUTPUT);     // Initializes the LED pin as output
  strip.begin();                // Turns the strip on
  strip.show();                 // Initializes all LEDs to 'off'
}

void loop()
{
  strip.clear();                        // Turns off all the LEDs in the ring
  digitalWrite(LED_PIN, LOW);           // Turns off the red LED

  int tempReading = getTempReading();   // Gets temp value from the method called
  
  Serial.print("Temp: ");               // Prints the prompt to the temperature
  Serial.print(tempReading);            // Prints the temperature value in the serial monitor
  Serial.print("\n");
  
  int index = map(tempReading, -40, 124, 0, 11);        // Maps the min and max of temp sensor to 
                                                        // the index, indicating number of LEDs.
  Serial.print("Index: ");              // Prints the prompt to the index 
  Serial.print(index);                  // Prints the index in the serial monitor
  Serial.print("\n");
  
  for(int i = 0; i <= index; i ++) {    // For as many values of index, 
    strip.setPixelColor(i, ORANGE);     // The LEDs are set to the color ORANGE
    strip.show();                       // The pixels are shown
  }
      strip.show();

  if(strip.getPixelColor(11)) {         // If the last LED is turned on, then 
    digitalWrite(LED_PIN, HIGH);        // The red LED is turned on
  }
  
  delay(500);               // Delays for 500ms
}

/*
Returns the value of the temperature from the temperature sensor
*/
int getTempReading() {
  float reading = analogRead(TEMP_PIN);       // Readings taken from analog pin from the temp sensor.
  float voltage = (float)reading * 5.0;       // Reading converter to millivoltage
  voltage /= 1024.0;                          // millivoltage converted to voltage
  float celsius = (voltage - 0.5) * 100;      // Voltage converted to celsius
  
  return celsius;             // Returns the value of the temp in celsius units.
}
