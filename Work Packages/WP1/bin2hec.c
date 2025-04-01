// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 1
// Exercise 4


#include <stdlib.h> //header files
#include <stdio.h>
#include <string.h>

//main function
int main(int argc, char *argv[]){
    
    // variable declaration
    char binaryInput[64];
    char * endptr; 

    /*This is condition handles input from 'stdin' and command line
    If no argument is provided 'fgets()' reads the input (max 16 char) through 'stdin' and stores it in 'binaryInput'
    and if it fails to read anything it returns NULL(endptr) and the error is handle through the 'printf()' line
    If an argument is provided, then 'strncpy()' copies the argument and stores it in 'binaryInput'
    Else, if more than 2 arguments are provided the program exist with return code.
    */
    if (argc == 1) {
        if (fgets(binaryInput, sizeof(binaryInput), stdin) == endptr) {
            printf("Conversion unsuccessful!\n");
            return 2;
        }

    //If an argument is provided, then 'strncpy()' copies the argument and stores it in 'binaryInput'
    } else if (argc == 2) {
        strncpy(binaryInput, argv[1], sizeof(binaryInput) - 1);

    // If more than 2 arguments are provided the program exist with return code.
    } else {
        printf("Conversion unsuccessful!\n");
        return 2;
    }

    // converts the binary string(binaryInput) into an long interger
    // base 2, so that it intrepets it as a binary value
    //'&endptr' it ends when an invalid binary number is found
    unsigned long binaryValue = strtoul(binaryInput, &endptr, 2);

    // if no valid convertion value is found exists with return 2
    if (binaryInput == endptr) {

        printf("Conversion unsuccessful!\n");
        return 2;

    } else {
        // the binanry value is converted hexadecimal value and printed
        printf("0x%02lX", binaryValue);
        printf("\n");
    }

    return 0;
}