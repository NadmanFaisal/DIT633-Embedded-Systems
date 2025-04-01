// (C) Mohamed Taha Jasser, Nadman Faisal, Zahid Hasan, group: 10 (2025)
// Work package 1
// Exercise 5

#include <stdio.h>     // Standard I/O library header
#include <stdlib.h>    // Standard library header, like rand and srand.
#include <time.h>      // Library header for time

#define MAX 100        // Defines the maximum number of the values in the table
#define MAXNUMBER 20   // Defines the maximum value of random numbers
#define MINNUMBER 0    // Defines the minimun value of random numbers



// ------ Function declarations ----------

// This function generates a set of random numbers
// and fills the table *tab with these numbers
void create_random(int *tab );

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq );

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq );

// ------ Function definitions ----------

// function to generate random numbers between 0-20 and add them into array[MAX]
void create_random(int tab[]){  // takes in the empty table
    srand(time(0)); // initalizer for random generator, similar to Ex 3, we make a new seed to generate new numbers
    for (int i = 0; i < MAX; i++) { // for each num in MAX nummb of vals in table
        int random_num = rand() % 21; // generate a random number between 0 and MAXNUMBER
        tab[i] = random_num; // add rand num into array
    }
}

// function to count the number of occurrences of each num between 0 and 20 (MAXNUMBER) in the table
void count_frequency(int tab[], int freq[]){  // takes in the table filled with random numbers and an empty frequency table
    for(int number = 0; number <= MAXNUMBER; number++) { // for each number up to & including the 20th number
        for(int i = 0; i < MAX; i++) { // for each of the 100 random numbers in the table
            if(tab[i] == number) { // if the number equals to the number we are looking for
                freq[number]++; // we add the occurrence of that number in since we found one occurrence of it.
            }
        }
    }
}

// function to print out the histogram containing the number and its occurrences
void draw_histogram(int freq[] ){ //takes in the filled in & sorted occurrences of numbers between 0-20
    int zero_occurrence = 0; // zero occurrence of the number
    for(int number = 0; number <= MAXNUMBER; number++){ // for each number up to & including the 20th number
        int amountOfX = 1; // amount of frequencies in the table. more like an index for the for loop
        if(freq[number] != zero_occurrence){ // as long as there is no zeroes in the table
            if(number < 10){ // if the number is less than 10
                printf("%d    ", number); // print the number with spaces 
            } else { // otherwise
                printf("%d   ", number); // print the number with 1 less space since the second digit is occupying that space
            }
            while (amountOfX <= freq[number]) { // while the amount of x is less than or equal to the amount of occurrences of a number
                printf("x"); // print one x
                amountOfX++; // add +1 to amount of x so we print next x and so on until amountOfX is over the frequency, meaning no more occurrences of that number
            }
            printf("\n"); // print next line to move to next number
        }
    }
}

// ------ Main -------------------------

// The main entry point for the program
//
// If you choose to go for the optional part
// Please modify it accordingly
int main (void){ // void as we decided to keep the MAX & MAX_NUMBER

    int table[MAX], n ; // array of 100 integers 
    int frequency[MAXNUMBER + 1]; // array of 21 frequencies (since 0 counts too) of 100 integers from 0-20

    for(int i = 0; i <= MAXNUMBER; i++) { // for each value in the table up to MAXNUMBER
        frequency[i] = 0; // Clear the random assigned numbers
    }

    create_random(table); // generate random numbers between 0-20 and add them into table[MAX]

    count_frequency(table, frequency); // count the frequency gathered from the table array and put the occurrences it in the frequency
    
    draw_histogram(frequency); // finally print the histogram for the occurrences of the numbers in the random generated table.
}
