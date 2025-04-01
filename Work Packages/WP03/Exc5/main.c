// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 3
// Exercise 5
// Submission code: 482740 (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50              // The length of array
#define MULTIPLIER 2        // Constant used to multiply

/*
This method prints the contents of an array by looping 
through the array and printing its contents. 

The method takes two parameters - pointer to the index 
and the pointer to the first element of the array itself.
*/
void printArray(int *index, int *array) {
    printf("The numbers are: ");
    for(*index = 0; *index < MAX; ++*index) {       // loops through the array
        printf("%d ", array[*index]);               // and prints the integers in the array
    }
    printf("\n");
}

/*
This method is responsible for multiplying the contents of an 
array. 

Takes two parameters - pointer to the index to loop through, and 
pointer to the first element of the array.
*/
void multiplyArray(int *index, int *array) {
    for(*index = 0; *index < MAX; ++*index) {               // Loops through the whole array
        array[*index] = array[*index] * MULTIPLIER;         // and multiplies each element with MULTIPLIER
    }
}

int main(int argc, char *argv[]) {
    int array[MAX];                 // Initializes the array of MAX size on the stack
    int i;                          // Variable used as index
    int *pI = &i;                   // Pointer to the index variable
    int randomNumber;               // Variable to hold randomly generater number

    srand(time(NULL));              // seeds the random number generator base on time

    for(*pI = 0; *pI < MAX; ++*pI) {        // Loops through the array and 
        randomNumber = rand() % 99 + 1;     // stores a random number in varialbe
        array[*pI] = randomNumber;          // assigns the randomNumber to the array in the index
    }


    printf("The value of the address of the array (pointer) is: %p\n", array);      // Prints the address of the array
    printf("First integer in the array is (array[0]): %d\n", array[0]);             // Prints the first integer in the array at position 0
    printf("The last integer in the array is: %d\n", array[MAX - 1]);               // Prints the last integer in the array
    printf("The size of an integer (number of bytes) is: %ld\n", sizeof(int));      // Prints the number of bytes of an integer datatype
    printf("The size of the whole array in bytes is: %ld\n", sizeof(array));        // Prints the size of the whole array in bytes

    printArray(pI, array);              // Prints the array using pointer to index and pointer to the first element of an array
    multiplyArray(pI, array);           // Multiplies the array using pointer to index and pointer to the first element of an array
    printArray(pI, array);              // Prints the array using pointer to index and pointer to the first element of an array
}