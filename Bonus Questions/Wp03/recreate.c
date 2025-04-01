#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void setMatrixValue(int size_1, int size_2, int matrix[size_1][size_2], int matrix_2[size_1][size_2]) {
    char string[256];
    printf("Input the elements of the matrix 1: ");
    fgets(string, sizeof(string), stdin);

    char *token = strtok(string, " ");
    for(int i = 0; i < size_1; i++) {
        for(int j = 0; j < size_2; j++) {
            matrix[i][j] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    if(token != NULL) {
        printf("Invalid number of inputs. TERMINATED!\n");
        exit(0);
    }

    printf("Input the elements of the matrix 2: ");
    fgets(string, sizeof(string), stdin);

    token = strtok(string, " ");
    for(int i = 0; i < size_1; i++) {
        for(int j = 0; j < size_2; j++) {
            matrix_2[i][j] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    if(token != NULL) {
        printf("Invalid number of inputs. TERMINATED!\n");
        exit(0);
    }
}

void addMatrixes(int size1, int size2, int matrix1[size1][size2], int matrix2[size1][size2]) {
    int result[size1][size2];

    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    for(int i = 0; i < size1; i++) {
        for(int j = 0; j < size2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    int size_1;
    int size_2;
    printf("Input the size: ");
    scanf("%d %d", &size_1, &size_2);
    clearBuffer();

    printf("Size 1: %d\n", size_1);
    printf("Size 2: %d\n", size_2);

    int matrix_1[size_1][size_2];
    int matrix_2[size_1][size_2];

    setMatrixValue(size_1, size_2, matrix_1, matrix_2);
    addMatrixes(size_1, size_2, matrix_1, matrix_2);

    return 0;
}