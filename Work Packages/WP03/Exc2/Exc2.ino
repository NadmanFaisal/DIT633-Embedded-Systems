// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 3
// Exercise 2
// Submission code: 482740 (provided by your TA-s)

#define RED_PIN 2 // defining pin for red led
#define GREEN_PIN 4 // defining pin for green led
#define YELLOW_PIN 7 // defining pin for yellow led

#define DHT_TEMPPIN A0 // defining temperature pin
#define DHT_PHOTOPIN A1 // defining photoresistor pin 

int periodicity = 1000; // defining period value


void setup()
{
  Serial.begin(115200); // initializing the serial
  pinMode(RED_PIN, OUTPUT); // initializing red led as output
  pinMode(GREEN_PIN, OUTPUT); // initilizing green led as output
  pinMode(YELLOW_PIN, OUTPUT); // initilizing yellow led as output
  
}

void loop()
{
  
  digitalWrite(RED_PIN, LOW); // turing red led off
  digitalWrite(GREEN_PIN, LOW); // turing green led off
  digitalWrite(YELLOW_PIN, LOW); // turing yellow led off
  
  int tempVal = analogRead(DHT_TEMPPIN); // storing the temperature analog value
  
  float voltage = (tempVal/1024.0) * 5.0; //convert the ADC reading to voltage  
  float temperature = (voltage - .5) * 100; // convert the voltage to temperature in degrees
  
  
  int photoSen = analogRead(DHT_PHOTOPIN); // storing the photoresistor value
  int perPhoto = map(photoSen, 1017, 344, 0, 100); // mapping the photoresistor value to (0-100)
  
  if((perPhoto <= 100 && perPhoto >=61)){ // check if photoresistor value is between 100-60
    if(temperature >= 21){ // check if temperature is above 21
      digitalWrite(GREEN_PIN, HIGH); // turn green led on
    }else if (temperature < 21){ // check if temperature is below 21
      digitalWrite(YELLOW_PIN, HIGH); // turn yellow led on
    }
  }
  
  if((perPhoto <= 60 && perPhoto >=21)){ // check if photoresistor value is between 60-21
    if(temperature <= 20 && temperature >= 0){ // check if temperature is between 20-0
      digitalWrite(GREEN_PIN, HIGH); // turn green led on
    } else if (temperature > 21){ // check if temperature is above 21
      digitalWrite(RED_PIN, HIGH); // turn red led on
    } else if (temperature < 0){ // check if temperature is below 0
      digitalWrite(YELLOW_PIN, HIGH); // turn yellow led on
    }
  }
  
  if((perPhoto <= 20 && perPhoto >=1)){ // check if photoresistor value is between 20-1
    if(temperature <= 0 && temperature >= -12){ // check if temperature is between 0-(-12)
      digitalWrite(GREEN_PIN, HIGH); // turn green led on
    } else if (temperature > 0){ // check if temperature is above 0
      digitalWrite(RED_PIN, HIGH); // turn red led on
    } else if (temperature < -12){ // check if temperature is below -12
      digitalWrite(YELLOW_PIN, HIGH); // turn yellow led on
    }
    
  } 
  
  if(perPhoto == 0){ // check if photoresistor value is equal to 0
    if(temperature < -12){ // check if temperature is below -12
      digitalWrite(GREEN_PIN, HIGH); // turn green led on
    } else if (temperature > -12){ // check if temperature is above -12
      digitalWrite(RED_PIN, HIGH); // turn red led on
    }
    
  } 
  
  Serial.println("Photoresistor: "); // printline for Photoresistor
  Serial.println(perPhoto); // print Photoresistor value
  Serial.print("degrees C: "); // printline for for temperature
  Serial.println(temperature); // print temperature value
  delay(periodicity); // dealy of 1 second
}