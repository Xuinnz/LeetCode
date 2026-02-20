bool solve(char** board);
bool isValid(char** board, int row, int col, char nums);

void solveSudoku(char** board, int boardSize, int* boardColSize) {
    solve(board);
}

bool solve(char** board){
    char nums[10] = "123456789";
    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            if (board[row][col] == '.') {
                for(int i = 0; i < 9; i++){
                    if (isValid(board, row, col, nums[i])){
                        board[row][col] = nums[i];
                        if (solve(board)){
                            return true;
                        }
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool isValid(char** board, int row, int col, char nums){
    for(int i = 0; i < 9; i++){
        if (board[row][i] == nums) return false;
        else if(board[i][col] == nums) return false;
    }
    int box_row = (row / 3) * 3;
    int box_col = (col / 3) * 3;
    for(int k = box_row; k < box_row + 3; k++){
        for(int j = box_col; j < box_col + 3; j++){
            if (board[k][j] == nums) return false;
        }
    }
    return true;
}
