#include <stdio.h>
#include <stdlib.h>     // Library to use functions such as 'atoi' and 'exit'
#include <string.h>     // Library to use string tokenizer method (strtok)
#include <ctype.h>      // Library to compare the type of chars

#define MAX_SIZE 4      // Max size of columns and rows of matrices


// Method declarations

// Takes matrixes as parameters and sets their values to their respective columns and rows
void setMatrixValues(int *row, int *column, int firstMatrix[*row][*column], int secondMatrix[*row][*column]);
// Sets the values of the pointers to the matrixes rows and columns dynamically
void setMatrixSize(int *firstMatrixSize, int *secondMatrixSize);
// Takes two matrixes as parameters and adds them together
void addMatrixes(int *row, int *column, int firstMatrix[*row][*column], int secondMatrix[*row][*column]);

int main(int argc, char *argv[]) {
    int row;                            // Variable the stores the rows of the matrices
    int column;                         // Variable the stores the columns of the matrices
    int *pRow = &row;                   // Pointer to the row to pass as arguements to methods
    int *pColumn = &column;             // Pointer to the column to pass as arguements to methods

    setMatrixSize(pRow, pColumn);       // Sets the values of the rows and columns to the user typed values

    int matrix_1[*pRow][*pColumn];      // Using the user typed values, matrix_1 is initialized
    int matrix_2[*pRow][*pColumn];      // Using the user typed values, matrix_2 is initialized

    setMatrixValues(pRow, pColumn, matrix_1, matrix_2);             // The values taken from the user are set to the matrices

    addMatrixes(pRow, pColumn, matrix_1, matrix_2);                 // The matrices are added together and the sum is printed in the console

}

/*
This method takes pointers to row and column variables, the first element 
of the matrix_1 and the first element of the matrix_2. 
Input is taken from the user and stored in temporary variables. 

String tokenizer is used to break the multiple inputs entered by the user. 
The way string tokenizer works in this method is it breaks the input when 
a space is discovered. The inputs are then converted to integers and 
then assigned to the matrices. 

If invalid inputs provided by the user, the program stops. Invalid inputs 
include inputs which are not numbers, or inputs which are shorter than 
the indices of the matrices. 
*/
void setMatrixValues(int *row, int *column, int firstMatrix[*row][*column], int secondMatrix[*row][*column]) {
    char temp2[200];                // Variable to hold the input for the first matrix
    char temp3[200];                // Variable to hold the input for the second matrix

    printf("Input elements of matrix 1: ");     // Prompts the user to input the elements for the first matrix
    fgets(temp2, sizeof(temp2), stdin);         // Stores the input taken from the user in 'temp2' variable

    printf("Input elements of matrix 2: ");     // Prompts the user to input the elements for the first matrix
    fgets(temp3, sizeof(temp3), stdin);         // Stores the input taken from the user in 'temp2' variable

    if(*row < 2 || *column < 2) {               // If the number of rows and colums cannot be less than 2
        printf("invalid\n");                    // If less than 2, prints invalid and
        exit(0);                                // exits the program
    }

    char *token = strtok(temp2, " ");           // Pointer which stores the address of the first char found in temp2
                                                // finds the first occurance of a space, and replaces with a null-terminator
                                                // and returns the pointer to the first character (string)
    for(int i = 0; i < *row; i++) {             // loops through the rows of the first matrix
        for(int j = 0; j < *column; j++) {      // loops through the columns of the first matrix
            if(token == NULL) {                 // If there are less inputs than the number of columns/rows specified by user,
                printf("invalid\n");            // prints 'invalid' and 
                exit(0);                        // exits the program
            }
            if(isalpha(*token)) {               // If the character is an alphabet,
                printf("invalid\n");            // prints invalid and 
                exit(0);                        // exits the program
            }
            firstMatrix[i][j] = atoi(token);    // Assigns the converted char to int values to the respective cells of the matrix
            token = strtok(NULL, " ");          // Finds the next character which is NOT a space, and returns a pointer to the new found char
        }
    }

    if(token != NULL) {                 // If there are inputs lets (more inputs than specified rows and columns),
        printf("invalid\n");            // prints invalid
        exit(0);                        // and exits the program
    }

    token = strtok(temp3, " ");                 // Pointer which stores the address of the first char found in temp3
                                                // finds the first occurance of a space, and replaces with a null-terminator
                                                // and returns the pointer to the first character (string)
    for(int i = 0; i < *row; i++) {             // loops through the rows of the second matrix
        for(int j = 0; j < *column; j++) {      // loops through the columns of the second matrix
            if(token == NULL) {                 // If there are less inputs than the number of columns/rows specified by user,
                printf("invalid\n");            // prints 'invalid' and 
                exit(0);                        // exits the program
            }
            if(isalpha(*token)) {               // If the character is an alphabet,
                printf("invalid\n");            // prints invalid and 
                exit(0);                        // exits from the program
            }
            secondMatrix[i][j] = atoi(token);   // Assigns the converted char to int values to the respective cells of the matrix
            token = strtok(NULL, " ");          // Finds the next character which is NOT a space, and returns a pointer to the new found char
        }
    }

    if(token != NULL) {             // If there are inputs lets (more inputs than specified rows and columns),
        printf("invalid\n");        // prints invalid and
        exit(0);                    // exits the program
    }

}

/*
This method takes pointers to row and column variables, and sets their values 
according to the user's inputs. After taking the users inputs, the input 
is then broken down into individual characters with string tokenizer. The 
input is then converted to integers, and the pointers to the row and column 
are assigned the values. 
*/
void setMatrixSize(int *row, int *column) {
    char temp[200];                         // Variable that holds the string input from the user
    printf("Input the size: ");             // Prompts the user to give the input size
    fgets(temp, sizeof(temp), stdin);       // Stores the string in 'temp' variable

    char *token = strtok(temp, " ");        // Pointer which stores the address of the first char found in temp

    for(int i = 0; i < 2; i++) {            // Since the maximum number of inputs can be two, loops twice 
        if(i == 0) {
            if(atoi(token) > MAX_SIZE) {    // If the column size is greater than 4, 
                printf("invalid\n");        // prints invalid and 
                exit(0);                    // exits the program
            }
            *row = atoi(token);             // The first input is stored in the memory address of row
        } else {
            if(atoi(token) > MAX_SIZE) {    // If the column size is greater than 4, 
                printf("invalid\n");        // prints invalid and 
                exit(0);                    // exits the program
            }
            *column = atoi(token);          // The second input is stored in the memory address of column
        }
        token = strtok(NULL, " ");          // // Finds the next character which is NOT a space, and returns a pointer to the new found char
    }
}

/*
The pointers to the row and column variable are taken as parameters. The 
pointers to the first elements to the matrix_1 and matrix_2 are also taken. 

A new matrix 'result' is initialized, containing the same rows and columns 
as the other matrices. Two for-loops are used to iterate through the 
rows and columns of the matrices, and added. The resultant sum is then 
assigned to the respective cells in the result matrix. 

The result matrix is then printed in the console. 
*/
void addMatrixes(int *row, int *column, int firstMatrix[*row][*column], int secondMatrix[*row][*column]) {
    int result[*row][*column];      // Matrix that holds the sum of the two matrices

    for(int i = 0; i < *row; i++) {                                             // Loops through the rows of the result matrix
        for(int j = 0; j < *column; j++) {                                      // Loops through the columns of the result matrix
            result[i][j] = firstMatrix[i][j] + secondMatrix[i][j];              // Stores the summation of the first and second matrix
        }
    }

    printf("The sum is: \n");                       // The sum is the printed
    for(int i = 0; i < *row; i++) {                 // Loops through the rows of the result matrix
        for(int j = 0; j < *column; j++) {          // Loops through the columns of the result matrix
            printf("%d ", result[i][j]);            // Prints the summation of the first and second matrix
        }
        printf("\n");                               // Moves on to the next row
    }

}