/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int *ans = malloc(sizeof(int) * matrixRowSize * matrixColSize);
    
    int x_min = 0, x_max = matrixRowSize - 1, y_min = 0, y_max = matrixColSize - 1;
    
    int order = 0;
    
    int x = 0, y = 0;
    
    int counter = 0;
    while (counter < matrixRowSize * matrixColSize) {
        switch(order) {
            case 0 : 
                while (y <= y_max) {
                    ans[counter] = matrix[x][y];
                    counter++;
                    y++;
                }
                y--;
                x_min++;
                x++;
                break;     
            case 1 :  
                while (x <= x_max) {
                    ans[counter] = matrix[x][y];
                    counter++;
                    x++;
                }
                x--;
                y_max--;
                y--;
                break;  
            case 2 :  
                while (y >= y_min) {
                    ans[counter] = matrix[x][y];
                    counter++;
                    y--;
                }
                y++;
                x_max--;
                x--;
                break;   
            case 3 :  
                while (x >= x_min) {
                    ans[counter] = matrix[x][y];
                    counter++;
                    x--;
                }
                x++;
                y_min++;
                y++;
                break;    
        }
        order = (order + 1) % 4;
    }
    
    return ans;
}