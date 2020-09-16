class TicTacToe {
public:
    /** Initialize your data structure here. */
    int size, d1, d2;
    int *rows, *cols;
    TicTacToe(int n) {
        size = n;
        d1 = d2 = 0;
        rows = new int [n], cols = new int [n];
        for(int i = 0; i < n; i++) rows[i] = 0, cols[i] = 0;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1){
            rows[row]++; 
            cols[col]++;
            if(row == col) 
                d1++;
            if(row + col == size - 1) 
                d2++;
            if(rows[row] == size || cols[col] == size || d1 == size || d2 == size) 
                return 1;
        }
        else { //player 2
            rows[row] --; 
            cols[col]--;
            if(row == col) 
                d1--;
            if(row + col == size - 1) 
                d2--;
            if(rows[row] == -size || cols[col] == -size || d1 == -size || d2 == -size) 
                return 2;
        }

        return 0;
    }