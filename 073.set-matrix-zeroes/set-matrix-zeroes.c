void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int allRow = 0, allCol = 0;
    for (int i = 0; i < matrixRowSize; i++) 
        if (matrix[i][0] == 0) 
            allRow = 1;
                
    for (int j = 0; j < matrixColSize; j++)
        if (matrix[0][j] == 0)
            allCol = 1;
        
    for (int i = 0; i < matrixRowSize; i++) 
        for (int j = 0; j < matrixColSize; j++)
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
                
    for (int i = 1; i < matrixRowSize; i++) 
        if (matrix[i][0] == 0)
            for (int j = 1; j < matrixColSize; j++)
                matrix[i][j] = 0;
                
    for (int j = 1; j < matrixColSize; j++)
        if (matrix[0][j] == 0)
            for (int i = 1; i < matrixRowSize; i++) 
                matrix[i][j] = 0;
    
    if (allRow == 1)
        for (int i = 0; i < matrixRowSize; i++) 
            matrix[i][0] = 0;
            
    if (allCol == 1)
        for (int j = 0; j < matrixColSize; j++)
            matrix[0][j] = 0;
}