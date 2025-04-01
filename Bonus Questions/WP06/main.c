#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The size of string variable
#define MAX_LENGTH_OF_ELEMENT 256

// The size of an array of strings
#define NUMBER_OF_ELEMENTS 5

/*
This method is responsible for clearing buffer, by 
getting characters untill newline character or EOF 
is found. 
*/
void clearBuffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF) { } // Loops untill a newline character is found
}

/*
This method is responsible for printing the strings in an array. 
This method takes the pointer to the array of strings, and a 
pointer to the itemsRemoved which is used to keep track of the 
number of items removed. 
*/
void printArray(char **array, int *pItemsRemoved) {
    for(int i = 0; i < NUMBER_OF_ELEMENTS - (*pItemsRemoved); i++) {        // Loops untill the number of elements in the array
        printf("%s\n", array[i]);                                           // Prints the array
    }
    printf("\n");
}

/*
This method is used to get the length of a string. This method 
taken the pointer to the string as parameter, and increments it's
counter untill null-terminator character is found. 
*/
int getLength (char string[]) {
    int counter = 0;                            // Counter to keep track of the length
    while (string[counter] != '\0') {           // Loops untill the null-terminator character is found
        counter++;                              // Increments counter
    }

    return counter;                             // Returns counter
}

/*
This method returns the pointer to the string of array after reallocating 
the memory for it. This method finds the shortest string (not the first 
occurance), and removes it from the array. The array's memory is then re-
allocated as the array is shortened. 
*/
char ** shortenArray(char **array, int *pItemsRemoved) {
    int shortestLength = getLength(array[0]);                               // Keeps track of the shortest string
    int shortestIndex = 0;                                                  // Keeps track of the index of the shortest string

    for(int i = 0; i < NUMBER_OF_ELEMENTS - (*pItemsRemoved); i++) {        // Loops untill the last string of the array
        int newLength = getLength(array[i]);                                // The length of the elements are kept track
        if(shortestLength > newLength) {                                    // If the new found length is greater than the shortest string found before, 
            shortestLength = newLength;                                     // Replaces the first length with the new found length which is shorter and 
            shortestIndex = i;                                              // replaces the shortestIndex to the current index.
        }
    }
    printf("Shortest string removed: %s\n", array[shortestIndex]);          // Prints the string which is to be removed


    free(array[shortestIndex]);                                                             // Memory allocated for that string is removed
    for (int i = shortestIndex; i < NUMBER_OF_ELEMENTS - (*pItemsRemoved); i++) {           // Loops from the index of the string to be removed, untill
                                                                                            // the end of the array and 
        array[i] = array[i + 1];                                                            // shifts all the elements to the left by 1
    }

    (*pItemsRemoved)++;                                                                     // Increments the value stored at this address to keep track of 
                                                                                            // items removed.
    array = realloc(array, (NUMBER_OF_ELEMENTS - *pItemsRemoved) * sizeof(char *));         // Reallocates memory for the shortened array
    return array;                                                                           // Returns the pointer to the array.
}

int main (int argc, char **argv) {
    
    int itemsRemoved = 0;                                                           // Variable to keep track of items removed

    char string[MAX_LENGTH_OF_ELEMENT];                                             // Variable to keep track of user inputs
    char **strings = (char **) malloc(NUMBER_OF_ELEMENTS * sizeof(char *));         // Allocates memory for the array of pointers

    for (int i = 0; i < NUMBER_OF_ELEMENTS; ++i) {                                  // Loops untill the max number of elements that should be in the array
        strings[i] = (char *)malloc(MAX_LENGTH_OF_ELEMENT + sizeof(char));          // Allocates memory for the string and makes the pointer in the 
                                                                                    // array to point to that specific memory block
        scanf("%s", string);                                                        // Takes the user input from console
        clearBuffer();                                                              // Clears buffer
        strcpy(strings[i], string);                                                 // Copies the user input into the array
    }

    strings = shortenArray(strings, &itemsRemoved);                                 // Gets the shortened array
    printf("Array after removal:\n");
    printArray(strings, &itemsRemoved);                                             // Prints the array with its elements

    free(strings);                                                                  // Frees up memory allocated for the array of pointers
}