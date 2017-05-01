void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    for (int i = 0; i < (matrixRowSize >> 1) + (matrixRowSize & 1); i++) 
        for (int j = 0; j < (matrixColSize >> 1); j++) {
            int t = matrix[i][j];
            matrix[i][j] = matrix[matrixRowSize - j - 1][i];
            
            matrix[matrixRowSize - j - 1][i] = matrix[matrixRowSize - i - 1][matrixColSize - j - 1];
            
            matrix[matrixRowSize - i - 1][matrixColSize - j - 1] = matrix[j][matrixColSize - i - 1];
            
            matrix[j][matrixColSize - i - 1] = t;
        }
}