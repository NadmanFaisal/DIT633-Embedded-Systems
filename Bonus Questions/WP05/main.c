#include <stdio.h>
#include <stdlib.h>

/* Unsigned char renamed to byte */
typedef unsigned char byte;

/*
This method is responsible for inserting bits into the 
pointer to the destination using the bits from the source
and bitshifting. 

    *destination - where the bits are to be inserted
    source - where the bits are taken from
    makeSpace - space needed for the next bits

*/
void insertBits(byte *destination, byte source, int makeSpace) {
    *destination = *destination | source;               // Masks the bits into the destination
    *destination = *destination << makeSpace;           // Makes space for the next bits to be inserted
}

/*
This method is responsible for converting a decimal value to 
a hexadecimal value. 
*/
void convertToHexa(byte *hexadecimalValue, byte decimalValue, int *index) {
    byte temp;                                  // Variable to hold the remainder

    while(decimalValue != 0) {                  // While the quotient doesnt reach to 0, 
        temp = decimalValue % 16;               // Stores remainder in temp variable 

        if(temp < 10) {                         // If the temp is less than 10, 
            temp = temp + 48;                   // Adds 48 to the temp as numbers less than 10 are integers and integers
                                                // in ascii values start from 48.
        } else {                                // But if the temp is greater than 10, 
            temp = temp + 55;                   // adds 55 to the temp as numbers greater than 10 are to be alphabets, and 
                                                // alphabets in ascii value start from 55.
        }
        hexadecimalValue[(*index)++] = temp;    // Stores the remainder and increments the pointer to the index
        decimalValue = decimalValue / 16;       // Stores the quotient in the variable itself.
    }
}

int main(int argc, char *argv[]) {
    if(argc != 6) {                                     // If incorrect number of arguements is given, 
        printf("Invalid number of arguements.\n");      // Prompts an error message and
        return 0;                                       // stops the program
    }

    byte engine_on = atoi(argv[1]);                     // Converts the frist arguement to integer
    byte floor_pos = atoi(argv[2]);                     // Converts the second arg to int
    byte door_pos = atoi(argv[3]);                      // Converts the third arg to int
    byte brake1 = atoi(argv[4]);                        // Converts the fourth arg to int
    byte brake2 = atoi(argv[5]);                        // Converts the fifth arg to int
    byte result = 0;

    if(engine_on > 0b1) {                               // If the engine_on variable is out of range of 0 to 1
        printf("Invalid range for engine_on");
        return 0;
    } else if(floor_pos > 0b111) {                      // If the floor_pos variable is out of range of 0 to 7
        printf("Invalid range for floor_pos");
        return 0;
    } else if(door_pos > 0b11) {                        // If door_pos is out of range of 0 to 3
        printf("Invalid range for floor_pos");
        return 0;
    } else if(brake1 > 0b1) {                           // If brake1 is out of range of 0 to 1
        printf("Invalid range for floor_pos");
        return 0;
    } else if(brake2 > 0b1) {                           // If brake2 is out of range of 0 to 1
        printf("Invalid range for floor_pos");
        return 0;
    }

    insertBits(&result, engine_on, 3);                  // Inserts bits taken from engine_on, into result, and makes space for floor_pos
    insertBits(&result, floor_pos, 2);                  // Inserts bits taken from floop_pos, into result, and makes space for door_pos
    insertBits(&result, door_pos, 1);                   // Inserts bits taken from door_pos, into result, and makes space for brake1
    insertBits(&result, brake1, 1);                     // Inserts bits taken from brake1, into result, and makes space for brake2
    insertBits(&result, brake2, 0);                     // Inserts bits taken from brake2, into result.

    printf("Bit shifted number: %d\n", result);         // prints the resultant decimal value

    byte hexa_val[100];                         // Variable to store hexadecimal value
    int i = 1;                                  // Index required for storing and printing hexadecimal vals
    convertToHexa(hexa_val, result, &i);        // Converts decimal to hexadecimal

    printf("0x");
    for(int j = i - 1; j > 0; j--) {            // Loops through backwards as the converter stores the values backwards
        printf("%c", hexa_val[j]);              // Prints the hexadecimal values
    }

    printf("\n");

}