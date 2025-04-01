// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 3
// Exercise 3.2
// Submission code: 482740 (provided by your TA-s)

#define ROW1 11 // defining pin for row1
#define ROW2 10 // defining pin for row2
#define ROW3 9 // defining pin for row3
#define ROW4 8 // defining pin for row4
#define COLUMN1 7 // defining pin for column1
#define COLUMN2 6 // defining pin for column2
#define COLUMN3 5 // defining pin for column3
#define COLUMN4 4 // defining pin for column4

int oneSec = 1000; // storing the seconds value

void setup() {
  Serial.begin(9600); // initializing Serial
  
  pinMode(ROW1, OUTPUT); // initializing row1 as output
  pinMode(ROW2, OUTPUT); // initializing row2 as output
  pinMode(ROW3, OUTPUT); // initializing row3 as output
  pinMode(ROW4, OUTPUT); // initializing row4 as output
  
  pinMode(COLUMN1, INPUT); // initializing column1 as input
  pinMode(COLUMN2, INPUT); // initializing column2 as input
  pinMode(COLUMN3, INPUT); // initializing column3 as input
  pinMode(COLUMN4, INPUT); // initializing column4 as input

}

void loop() {
  row1(); // calling row1 function
  row2(); // calling row2 function
  row3(); // calling row3 function
  row4(); // calling row4 function
  
}


void row1(){
  digitalWrite(ROW1, LOW); // turing row1 in to low
  digitalWrite(ROW2, HIGH); // turing row2 in to high
  digitalWrite(ROW3, HIGH); // turing row3 in to high
  digitalWrite(ROW4, HIGH); // turing row4 in to high
  
  if(digitalRead(COLUMN1) == LOW){ // check if column1 is low
    Serial.print("1"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN2) == LOW){ // check if column2 is low
    Serial.print("2"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN3) == LOW){ // check if column3 is low
    Serial.print("3"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN4) == LOW){ // check if column4 is low
    Serial.print("A"); // print the value
    delay(oneSec); //delay of 1 second
  }
  
}

void row2(){
  digitalWrite(ROW1, HIGH); // turing row1 to high
  digitalWrite(ROW2, LOW); // turing row2 to low
  digitalWrite(ROW3, HIGH); // turing row3 to high
  digitalWrite(ROW4, HIGH); // turing row4 to high
  
  if(digitalRead(COLUMN1) == LOW){ // check if column1 is low
    Serial.print("4"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN2) == LOW){ // check if column2 is low
    Serial.print("5"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN3) == LOW){ // check if column3 is low
    Serial.print("6"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN4) == LOW){ // check if column4 is low
    Serial.print("B"); // print the value
    delay(oneSec); //delay of 1 second
  }
  
}

void row3(){
  digitalWrite(ROW1, HIGH); // turing row1 to high
  digitalWrite(ROW2, HIGH); // turing row2 to high
  digitalWrite(ROW3, LOW); // turing row3 to low
  digitalWrite(ROW4, HIGH); // turing row4 to high
  
  if(digitalRead(COLUMN1) == LOW){ // check if column1 is low
    Serial.print("7"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN2) == LOW){ // check if column2 is low
    Serial.print("8"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN3) == LOW){ // check if column3 is low
    Serial.print("9"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN4) == LOW){ // check if column4 is low
    Serial.print("C"); // print the value
    delay(oneSec); //delay of 1 second
  }
  
}

void row4(){
  digitalWrite(ROW1, HIGH); // turing row1 to high
  digitalWrite(ROW2, HIGH); // turing row2 to high
  digitalWrite(ROW3, HIGH); // turing row3 to high
  digitalWrite(ROW4, LOW); // turing row4 to low
  
  if(digitalRead(COLUMN1) == LOW){ // check if column1 is low
    Serial.print("*"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN2) == LOW){ // check if column2 is low
    Serial.print("0"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN3) == LOW){ // check if column3 is low
    Serial.print("#"); // print the value
    delay(oneSec); //delay of 1 second
  } else if(digitalRead(COLUMN4) == LOW){ // check if column4 is low
    Serial.print("D"); // print the value
    delay(oneSec); //delay of 1 second
  }
  
}
