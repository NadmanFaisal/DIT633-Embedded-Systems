#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef unsigned char byte;

int main(int argc, char *argv[]) {
    // If there are 
    if(argc < 2) {
        printf("Error: No number provided. Please provide a number as a command line argument.\n");
        return 0;
    }
    
    // null terminator points towards the '\0'
    char *null_terminator;
    /*strtol converts the first arguement to long integer. If the returned value is of valid format, null_terminator will
    point towards '\0', or else it will point towards the first invalid character, which can be a non-number character.*/
    unsigned long int decimal_number = strtol(argv[1], &null_terminator, 10);
    if (*null_terminator != '\0') {
      printf("error: invalid number.\n");
      return 0;
    }

    unsigned long count_bit_digits = decimal_number;    // this variable is used to keep a copy of the 'decimal_number' to count the number of bits in it.
    unsigned long decimal_copy_1 = decimal_number;      // decimal_copy_1 is used to extract the first bit of the 'decimal_number'
    unsigned long decimal_copy = decimal_number;        // decimal_copy is used to count the number of 0s and 1s in the decimal_number's binary number
    unsigned long count = 0;        // count is used to keep track of the number of bits in the binary of 'decimal_number'
    int count1 = 0;                 // The count of 1s in the binary of 'decimal_number'
    int count0 = 0;                 // The count of 0s in the binary of 'decimal_number'

    // Counts the number of bits in a number by bitshifting the bits until there are no bits left and increments the count
    while(count_bit_digits) {
        count_bit_digits = count_bit_digits >> 1;
        count++;
    }

    // Prints the number which is taken from the 2nd arguement provided in the command line
    printf("Number: %lu\n", decimal_number);

    /*This for loop is used to shift the decimal_copy_1 to the right by the count of bits in the
    binary of the decimal_number. This allows us to extract the first bit of 'decimal_number' with
    the help of '&' operator with 1. The extracted bit is then printed out, and the decimal_copy_1
    is then replaced by the original value of decimal_number, ensuring correct bitshifting as the loop
    keeps decrementing the value of 'i'.*/
    printf("Binary: 0b");
    for(int i = count; i > 0; i--) {
        decimal_copy_1 = decimal_copy_1 >> (i - 1);
        int extracted_bit = decimal_copy_1 & 1;
        printf("%d", extracted_bit);
        decimal_copy_1 = decimal_number;
    }
    printf("\n");

    /*The decimal_copy is the copy of decimal_number, which is bit shifted to the right by 1.
    Each time before shifting the decimal copy, '&' operator is used to check if the last bit
    in the decimal_copy is a 0 or 1. According to the if statements, the count for 'count1' of 'count0'
    is incremented, which represents the number of 0s and 1s in the decimal_number's binary representation.
    */
    while(decimal_copy > 0) {
        if(decimal_copy & 1) {
            count1++;
        }
        else {
            count0++;
        }

        decimal_copy = decimal_copy >> 1;
    }

    // Prints the number of 0s and 1s in the binary representation of decimal_number
    printf("Number of 0s: %d\n", count0);
    printf("Number of 1s: %d\n", count1);
}