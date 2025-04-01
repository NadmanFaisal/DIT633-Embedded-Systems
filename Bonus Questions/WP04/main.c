#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Counts the length of the string given as arguement */
int stringLength(char *string) {
    int counter = 0;                        // Variable to store the length of the string
    while (string[counter] != '\0') {       // Untill the null terminator is not enountered, 
        counter++;                          // counter variable is incremented.
    }
    return counter;             // Returns the counter, indicating the length of the string
}

/* Swaps two characters by taking pointers to the characters, and pointing them at the other's memory address */
void swap(char *firstChar, char *secondChar) {
    char tempChar = *firstChar;             // Holds the character of the firstChar pointer
    *firstChar = *secondChar;               // secondChar pointer's value copied into firstChar pointer
    *secondChar = tempChar;                 // tempChar value (value of firstChar) copied to secondChar pointer
}

/* 
Recursive method, which takes the string, the first and the last index, the storageArray, and the
count which keeps track of how many times the base case has been entered. The method keeps calling 
itself, swapping the characters of the string in the index firstIndex and the 'i' index of the 
for loop. It restores the original value of the string by swapping back to the original value of the 
string, in order to keep permutating correct values of the string. 
*/
void permutate(char *string, int firstIndex, int lastIndex, char **array, int *count) {
    
    // Base case
    if (firstIndex == lastIndex) {
        array[*count] = malloc((stringLength(string) + 1) * sizeof(char));          // Allocates memory to store the permutation of the string, 
                                                                                    // the block of memory is being pointed by the array pointer
        strcpy(array[*count], string);                                              // copies the permutattion of the string to the block of memory
        (*count)++;                                                                 // increments the count to keep track of the array index location
        return;                                                                     // exits recursive call.
    }

    for (int i = firstIndex; i <= lastIndex; i++) {                                 // loops untill last index is crossed, in order to swap values and permutate
        swap(&string[firstIndex], &string[i]);                                      // Swaps the characters
        permutate(string, firstIndex + 1, lastIndex, array, count);                 // calles itself again, but with the next index for the next character
        swap(&string[firstIndex], &string[i]);                                      // swaps back to the original value
    }
}

/* Finds the combinations for all the permutations of a string by taking its length as parameter */
long factorial(int length) {
    long factorial = 1;                     // Variable which holds the result of the factorial
    for(int i = 1; i <= length; i++) {      // Starts from length, and decrements
        factorial = factorial * i;          // and multiplies by the factorial variable
    }

    return factorial;                       // returns the factorial of the length of the string
}

int main(int argc, char *argv[]) {
    if (argc != 2) {                        // If the number of arguements is not correct,
        printf("Invalid arguements\n");     // prompts message and 
        return 0;                           // exits program
    }

    char *string = argv[1];                 // Takes the string from the second arguement
    char **storage;                         // Array to strings, where the permutations will be stored
    
    int length = stringLength(string);      // The length of the string
    int combinations = factorial(length);   // The number of string's permutation
    
    int count = 0;                          // Variable which keeps track of the base cases encountered in the recursive method
    
    storage = malloc(combinations * sizeof(char *));                        // Allocates enough memory for the array of strings.
    
    if(length > 10 || length < 0) {                                         // If the length of the string is more or less than 10 or 0, 
        printf("cannot be more than 10 characters.invalid\n");              // prompts appropiate error message and 
        return 0;                                                           // exits program
    }

    printf("All permutations of the string %s are: ", string);
    permutate(string, 0, length - 1, storage, &count);                      // Calls the permutate method to find all permutations of a string

    for(int i = 0; i < combinations; i++) {                     // For all the permutations of a given string, 
        printf("%s ", storage[i]);                              // each permutation is printed.
        free(storage[i]);                                       // Memory alloacted for that string is freed.
    }
    printf("\n");

    free(storage);                          // Memory allocated for the storage array is also freed.

    return 0;
}
