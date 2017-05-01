void clear(int i, int j, char** grid, int gridRowSize, int gridColSize) {
    grid[i][j] = '0';
    if ((i-1 >= 0) && (grid[i-1][j] == '1')) clear(i-1, j, grid, gridRowSize, gridColSize);
    if ((i+1 <= gridRowSize - 1) && (grid[i+1][j] == '1')) clear(i+1, j, grid, gridRowSize, gridColSize);
    if ((j-1 >= 0) && (grid[i][j-1] == '1')) clear(i, j-1, grid, gridRowSize, gridColSize);
    if ((j+1 <= gridColSize - 1) && (grid[i][j+1] == '1')) clear(i, j+1, grid, gridRowSize, gridColSize);
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    int ans = 0;
    for (int i = 0; i < gridRowSize; i++)
        for (int j = 0; j < gridColSize; j++)
            if (grid[i][j] == '1') {
                ans++;
                clear(i, j, grid, gridRowSize, gridColSize);
            }
    return ans;
}