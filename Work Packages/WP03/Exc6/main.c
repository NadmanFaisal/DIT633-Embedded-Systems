// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 3
// Exercise 6
// Submission code: 482740 (provided by your TA-s)

#include <stdio.h>
#include <string.h>

#define MAX 22              // Max length of the strings and taking into accunt for space for null terminator and new line character

/*
This method is responsible for returning the length of a string. 

Takes the pointer to the first character to the string as a parameter
*/
int getLength(char *string) {
    int counter = 0;                                                    // Variable to count the length of a string
    while(string[counter] != '\0' && string[counter] != '\n') {         // Loops until null-terminator or new-line character is not encountered
        counter++;                                                      // Increments counter
    }
    return counter;                                                     // Returns the counter (length of the string)
}

/*
This method copies a string form the source to the destination. 

Takes in two parameters - pointer to the destination, and pointer 
to the source from which the string is copied from. 
*/
void copyString(char *destination, char *source) {
    int stringLength = getLength(source);               // Length of the source is calculated

    for (int i = 0; i <= stringLength; i++) {           // Loops untill and including the end of the string
        if(i == stringLength) {                         // If the end of the string length is reached, then 
            destination[i] = '\0';                      // assigns a null-terminator to the destination string
            break;                                      // breaks the loop
        }
        destination[i] = source[i];                     // assigns the destination index to the source index
    }
}

int main(int argc, char *argv[]) {
    char string[MAX];                               // Creates a variable to hold string of MAX length on the stack
    char destination[MAX];                          // Create the destination of MAX length on the stack
    char destination2[MAX];                         // Creates another destination of MAX length on the stack

    if(argc == 2) {                                 // If an arguement is provided for the text file
        *string = *argv[1];                         // Content of the text file is assigned to string
    } else {                                        // If no arguement is provided, then 
        printf("Provide as input: ");               // Prompts to write an input
        fgets(string, sizeof(string), stdin);       // Stores the input to the string
    }

    if(string[getLength(string)] != '\n' && getLength(string) > 20) {       // Checks whether the string is of correct length by expecting special characters
                                                                            // at the end of the array
        printf("Incorrect string length\n");                                // Prompts the error and 
        return 0;                                                           // stops the program
    }

    printf("String is: %s\n", string);              // Prints th

    strcpy(destination, string);                    // Copies the string to destination using 'string' library
    printf("Destination1 is: %s\n", destination);   // Prints the destination to ensure expected outcome

    copyString(destination2, string);               // Copies the string to destination2 using new method
    printf("Destination 2: %s\n", destination2);    // Prints the destination2 to ensure expected outcome
}