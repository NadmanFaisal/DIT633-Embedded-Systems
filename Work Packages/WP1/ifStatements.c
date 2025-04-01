// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 1
// Exercise 1


#include <stdio.h> //header library file
#include <string.h>
#include <stdbool.h>

#define MAX_CHARACTER 30

int main(int argc, char * argv[]) {
    
    // variables that store the five sentences with 30 bytes memory
    char sentence1[MAX_CHARACTER + 1];
    char sentence2[MAX_CHARACTER + 1];
    char sentence3[MAX_CHARACTER + 1];
    char sentence4[MAX_CHARACTER + 1];
    char sentence5[MAX_CHARACTER + 1];

    // variable to store the inout number
    int num;
    // boolean to control the while loop
    bool validNum = true;
    
    /*Asks the user to write five sentences and stores them in allocated variabless
    and they are limited to 30 characters */
    printf("\nEnter five sentences: \n");
    fgets(sentence1, sizeof(sentence1), stdin); // reads limited number of character from the inout stream
    fflush(stdin); // clear input buffer
    fgets(sentence2, sizeof(sentence2), stdin);
    fflush(stdin); // clear input buffer
    fgets(sentence3, sizeof(sentence3), stdin);
    fflush(stdin); // clear input buffer
    fgets(sentence4, sizeof(sentence4), stdin);
    fflush(stdin); // clear input buffer
    fgets(sentence5, sizeof(sentence5), stdin);
    fflush(stdin); // clear input buffer

    /*The while condition is true and it asks for the user to inout a number
    The number should be between 1-5 and it prints the sentenec according to the sequence
    If the number is not between 1-5 it exists */
    do {
        printf("\nEnter a number between 1-5: \n");
        scanf("%d", &num);

        // Checks for duplicate strings within all the 5 sentences enetered
        if (strcmp(sentence1, sentence2) == 0 || strcmp(sentence1, sentence3) == 0 || strcmp(sentence1, sentence4) == 0 || strcmp(sentence1, sentence5) == 0 ||
            strcmp(sentence2, sentence3) == 0 || strcmp(sentence2, sentence4) == 0 || strcmp(sentence2, sentence5) == 0 || strcmp(sentence3, sentence4) == 0 ||
            strcmp(sentence3, sentence5) == 0 || strcmp(sentence4, sentence5) == 0) {
            printf("Duplicate found.\n");
            return 0;
        }

        // condition to check if the user entered input is between 1-5
        if (num == 1) {
            printf("%s", sentence1);
        } else if (num == 2){
            printf("%s", sentence2);
        } else if (num == 3){
            printf("%s", sentence3);
        } else if (num == 4){
            printf("%s", sentence4);
        } else if (num == 5){
            printf("%s", sentence5);
        } else {
            printf("Invalid number\n");
            validNum = false;
        }

        return 0;
    } while (validNum < 1 || validNum > 5);

    return 0;

}