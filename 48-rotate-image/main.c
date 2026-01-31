#include <stdio.h>
#include <stdlib.h>

// Function prototype
void rotate(int** matrix, int matrixSize, int* matrixColSize);

int main() {
    int n = 3;
    // 1. Setting up a 2D array dynamically for the function
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }

    // 2. Initializing the matrix:
    // 1 2 3
    // 4 5 6
    // 7 8 9
    int val = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = val++;
        }
    }

    printf("Original Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // 3. Call rotation logic
    int matrixColSize = n;
    rotate(matrix, n, &matrixColSize);

    printf("\nRotated Matrix (90 deg):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", matrix[i][j]);
        printf("\n");
    }

    // Cleanup
    for (int i = 0; i < n; i++) free(matrix[i]);
    free(matrix);

    return 0;
}
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int rows = matrixSize;
    int col = *matrixColSize;
    // for(int i = 0; i < rows; i++){ //transposing
    //     for(int j = i; j < col; j++){
    //         int temp = matrix[i][j];
    //         matrix[i][j] = matrix[j][i];
    //         matrix[j][i] = temp;
    //     }
    // }
    for(int i = 0; i < rows; i++){
        int start = 0;
        int end = col - 1;
        while(start < end){
            int temp = matrix[i][start];
            matrix[i][start] = matrix[i][end];
            matrix[i][end] = temp;
            start++;
            end--;
        }
    }
}   