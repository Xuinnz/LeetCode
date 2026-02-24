bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int i = 0;
    while (i + 1 < matrixSize && target >= matrix[i + 1][0]){
        i++;
    }
    int j = 0;
    while (j < *matrixColSize && target >= matrix[i][j]){
        if(target == matrix[i][j]) return true;
        j++;
    }
    return false;
}