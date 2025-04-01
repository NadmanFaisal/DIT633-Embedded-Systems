// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 6 (2025)
// Work package 1
// Exercise 2


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {

    // store the word
    char word; 

    // convert the shift string value to an integer
    int shiftValue = atoi(argv[1]);

    // print like for the user to enter word
    printf("Enter the word for encryption in UPPERCASE (Ctrl+D ends the program).\n");

    /*The while loop checks if the entered value is an EOF, if not it progresses
    For all the if condition we are using ASCII values.
    The first, second and third 'if condition' is used for UPPERCASE alphabets, lowercase alphabets and numbers accordingly
    The 'if condition' checks if the entered word is in valid range according to ASCII values
    If it is, we get the position/index of that word/number by subtracting the word from the base value(A,a,0)
    Then we shift the word according to the shiftValue we get from the argument line + add the position value and the base ASCII value,
    in order to avoid going past the last value we wrap it with 26 for alphabet and 10 for number*/

    // reads one character from the word and continues untill its not EOF(Ctrl + D or Z)
    while ((word = getchar()) != EOF) {

        //check if the character is uppercase through ASCII values
        if (word >= 'A' && word <= 'Z') {
            // getting the position of the word by transfering them into index.
            int position = word - 'A';
            //shifting the alphabets
            word = 'A' + ((position + shiftValue) % 26);

        } else if (word >= 'a' && word <= 'z') { //check if the character is lowercase through ASCII values
            // getting the position of the word by transfering them into index.
            int position = word - 'a';
             //shifting the alphabets
            word = 'a' + ((position + shiftValue) % 26);

        } else if (word >= '0' && word <= '9') { //check if the character is number through ASCII values
            // getting the position of the word by transfering them into index.
            int position = word - '0'; 
             //shifting the number
            word = '0' + ((position + shiftValue) % 10);
        }
        // print the encrypted word
        printf("%C", word); 
        
    }
    //return on success
    return 0; 


}