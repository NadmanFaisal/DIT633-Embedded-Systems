#include <stdio.h> // include library for print

#define MAX 10 // define MAX num of list, which is 10

// -------- Function declarations ----------

// function to search for num in list
int search_number(int number, int tab[], int size); // takes in number we r searching for,  the list and the size of list

// function to sort list
void sort(int number, int tab[]); // takes in length of list and the lsit

// function to swap between two numbers
void swap(int *num1, int *num2); // takes dereferenced value of both num addresses

// --------- Main Program ---------
int main(int argc, char* argv[]){ 

    int test[] = {1,2,34,5,67,3,23,12,13,10}; // list per specification

    int validNum = 12; // valid num to search for in search function
    int invalidNum = 4; // invalid num to search for in search function


    printf("Searched for 12: %d\n", search_number(validNum, test, MAX)); // print result of search function, searches for 12, which is in the list will return index 7
    printf("Searched for 12: %d\n", search_number(invalidNum, test, MAX)); // print result of search function, searches for 4, which is not in the list and will return index -1 (meaning it is not in the list)


    sort(MAX, test); // sort list by giving both list size and the list
        
    printf("Here is the sorted array: {"); // print out template for sorted array

    // loop through the array and print out the array
    for(int index = 0; index < MAX; index++){
        if(index == (MAX - 1)){ // making sure last num in the array
            printf("%d", test[index]); // doesnt include a comma to make the print look pretty
        } else {
            printf("%d,", test[index]);
        }
    }

    printf("}\n"); // close the array

}

// function to swap between two numbers
void swap(int *num1, int *num2){
    int temp; // temp variable

    temp = *num1; // assign temp variable to num1
    *num1 = *num2; // make num1 equal num2
    *num2 = temp; // give val of num1 (which is in temp) to num2
}

// function to search for num in list
int search_number(int number, int tab[], int size){
    // searches using linear search
    for(int i = 0; i < size; i++){ // for each num
        if(tab[i] == number){ // if num in list is equal to num
            return i; // return it since it is the first occurrence
        }
    }

    return -1; // if num dont exist return -1
}

// function to sort list
/*

For the sorting, we go through all num twice with two pointer.
one pointing at start of index and other iterating through the array.
every time it will find a smaller num it will swap with first index.
this ensure that if the smaller num is in the last index it will swap w/ first index
by making j = i + 1 it ensures it will not check numbers that have already been checked by i.

*/
void sort(int number, int tab[]){
    for(int i = 0; i < number; i++){ // for each num in array
        for(int j = i + 1; j < number; j++){ // for every other number in the array
            if(tab[j] < tab[i]){ // if next num is less than num
                swap(&tab[i], &tab[j]); // swap them
            }
        }
    }
}
