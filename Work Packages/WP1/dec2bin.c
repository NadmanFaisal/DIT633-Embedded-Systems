// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 1
// Exercise 4


#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

// variable declaration
long binaryNum8bits[8] = {0};
long binaryNum16bits[16] = {0};
long binaryNum32bits[32] = {0};
long binaryNum64bits[64] = {0};
long counter = 0;

/*
This method is used to help the user with the argument value.
When the user inputs '-h' in the argument value this method is called.
*/
void printHelp(){

    printf("\n");
    printf("***** HELP MENU *****\n");
    printf("For binanry conversion use './dec2bin.exe <parameter>'\n");
    printf("For hexdecimal conversion use './bin2hec.exe <parameter>'\n");
    printf("For pipeline conversion use './dec2bin.exe <parameter> | ./bin2hec.exe'\n");
    printf("\n");

} 

void binaryConvertion64bits(long number){

    while ( number > 0 ) {
        // storing remainder in binary array 
        binaryNum64bits[counter] = number % 2; 
        number = number / 2;
        // 'counter' corresponds to the index in the array
        counter++; 
    }
    // for loop used to reverse the array.
    for (int i = 63; i >= 0; i--) {
    printf("%ld",binaryNum64bits[i]);
    }
    printf("\n");

}


void binaryConvertion32bits(long number){

    while ( number > 0 ) {
        // storing remainder in binary array 
        binaryNum32bits[counter] = number % 2; 
        number = number / 2;
        // 'counter' corresponds to the index in the array
        counter++; 
    }
    // for loop used to reverse the array.
    for (int i = 31; i >= 0; i--) {
    printf("%ld",binaryNum32bits[i]);
    }
    printf("\n");

}

/*
This method is used to convert 16 bits binary value
The while loop checks if the input value(number) is valid 'bigger than 0'
If true, a modulus is done for the input value(number) and stored in a binary array 'binaryNum16bits[]'
Then we devide the input value(number) by 2 and it becomes the new input value (number)
Lastly, we reverse the matrix and print it.
*/
void binaryConvertion16bits(long number){

    while ( number > 0 ) {
        // storing remainder in binary array 
        binaryNum16bits[counter] = number % 2; 
        number = number / 2;
        // 'counter' corresponds to the index in the array
        counter++; 
    }
    // for loop used to reverse the array.
    for (int i = 15; i >= 0; i--) {
    printf("%ld",binaryNum16bits[i]);
    }
    printf("\n");

}

/*
This method is used to convert 8 bits binary value
The while loop checks if the input value(number) is valid 'bigger than 0'
If true, a modulus is done for the input value(number) and stored in a binary array 'binaryNum8bits[]'
Then we devide the input value(number) by 2 and it becomes the new input value (number)
Lastly, we reverse the matrix and print it.
*/
void binaryConvertion8bits(long number){

    while ( number > 0 ) {
        // storing remainder in binary array 
        binaryNum8bits[counter] = number % 2; 
        number = number / 2;
        // 'counter' corresponds to the index in the array
    0,  0;      counter++;
    }
    // for loop used to reverse the array.
    for (int i = 7; i >= 0; i--) {
    printf("%ld",binaryNum8bits[i]);
    }
    printf("\n");

}

// The main function
int main(int argc, char * argv[]){

    // variable declaration
    long MIN = 0; 
    char * endptr; // declare end of line point

    // The if condition checks if the argument given is '-h'
    // If true it triggers the 'printHelp()' method
    if (strcmp(argv[1],"-h") == 0) {

        printHelp();
        return 0;

    }
    
    // Convert input to unsigned long
    unsigned long number = strtoul(argv[1], &endptr, 10);
    
    /*
    This condition is used to check if the input value is valid for conversion
    We check if the number is less than 0 or bigger than the long max value
    or the the '*endptr' pointer did not detect '\0' after the numerical value.
    If any of the above condition becomes true the an output is given to the user
    and the program exits with 2.
    Otherwise, 'else' is executed.
    */
    if ((number < MIN || number > LONG_MAX) || (*endptr != '\0')) {
        printf("Conversion unsuccessful!\n");
        return 2;
    } else {
        
        //if the input value(number) is bigger than 8 bits the 16bit conversion 'binaryConvertion16bits()' function is triggered
        //otherwise the 8 bit conversion 'binaryConvertion8bits()' function is triggered
        if (number <= __UINT8_MAX__) {

        // calling the 16 bit conversion function
        binaryConvertion8bits(number);

        } else if (number <= __UINT16_MAX__) {

        // calling the 8 bit conversion function
        binaryConvertion16bits(number);

        } else if (number <= __UINT32_MAX__) {
            binaryConvertion32bits(number);
        } else {
            binaryConvertion64bits(number);
        }
    }

    return 0;
}