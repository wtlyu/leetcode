typedef struct {
    int *row;
    int *col;
    int diagonal;
    int rev_diagonal;
    int n;
} TicTacToe;

/** Initialize your data structure here. */
TicTacToe* ticTacToeCreate(int n) {
    TicTacToe* t = malloc(sizeof(TicTacToe));
    t -> n = n;
    t -> row = malloc(sizeof(int) * n);
    t -> col = malloc(sizeof(int) * n);
    t -> diagonal = 0;
    t -> rev_diagonal = 0;
    memset(t -> row, 0, sizeof(int) * n);
    memset(t -> col, 0, sizeof(int) * n);
    return t;
}

/** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
int ticTacToeMove(TicTacToe* obj, int row, int col, int player) {
    int n = obj -> n;
    player = (player << 1) - 3;
    obj -> col[col] += player;
    obj -> row[row] += player;
    obj -> diagonal += (row == col) * player;
    obj -> rev_diagonal += (row == (n - col - 1)) * player;
    if ((abs(obj -> col[col]) == n) || (abs(obj -> row[row]) == n) || (abs(obj -> diagonal) == n) || (abs(obj -> rev_diagonal) == n))
        return (player + 3) >> 1;
    return 0;
}

void ticTacToeFree(TicTacToe* obj) {
    free(obj -> row);
    free(obj -> col);
    free(obj);
}

/**
 * Your TicTacToe struct will be instantiated and called as such:
 * struct TicTacToe* obj = ticTacToeCreate(n);
 * int param_1 = ticTacToeMove(obj, row, col, player);
 * ticTacToeFree(obj);
 */