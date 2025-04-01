#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LENGTH 256
#define MAX_ELEMENTS 5

int printLength(char *string) {
    int counter = 0;
    while(string[counter] != '\0') {
        counter++;
    }

    return counter;
}

char **shortenArray(char **array) {
    int shortestLength = strlen(array[0]);
    int shortestIndex = 0;

    for(int i = 0; i < MAX_ELEMENTS; i++) {
        int newLength = strlen(array[i]);
        if(newLength < shortestLength) {
            shortestIndex = i;
            shortestLength = newLength;
        }
    }

    printf("Shortest string: %s\n", array[shortestIndex]);

    free(array[shortestIndex]);
    for(int i = shortestIndex; i < MAX_ELEMENTS - 1; i++) {
        array[i] = array[i + 1];
    }
    array = realloc(array, (MAX_ELEMENTS - 1) * sizeof(char *));
    return array;
}

void printArray(char **array) {
    for(int i = 0; i < MAX_ELEMENTS - 1; i++) {
        printf("%s ", array[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    char *string = (char *)malloc(MAX_STRING_LENGTH * sizeof(char));
    char **arrayOfStrings = (char **)malloc(MAX_ELEMENTS * sizeof(char *));

    for(int i = 0; i < MAX_ELEMENTS; i++) {
        printf("Type string: ");
        fgets(string, sizeof(string), stdin);
        string[strlen(string) - 1] = '\0';
        arrayOfStrings[i] = (char *)malloc(sizeof(char *));
        strcpy(arrayOfStrings[i], string);
    }

    shortenArray(arrayOfStrings);
    printArray(arrayOfStrings);

    free(string);
    for(int i = 0; i < MAX_ELEMENTS - 1; i++) {
        free(arrayOfStrings[i]);
    }
    free(arrayOfStrings);
    return 0;
}