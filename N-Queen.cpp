class Solution {
public:
    int _n;

    bool isValid(vector<string>& board, int row, int col) {
        // Check the column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check the upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check the upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < _n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void core(int n , int row, vector<string> board, vector<vector<string>>& ans) {
        if (row == _n) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < _n; col++) {
            if (isValid(board, row, col)) {
                vector<string> newBoard = board ;
                newBoard[row][col] = 'Q';
                if(n==1){
                    ans.push_back(newBoard) ;
                    return ;
                }
                else{
                    core(n-1 , row + 1, newBoard, ans);
                }
                // No need to backtrack as board is passed by value
            }
        }

        return ;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        _n = n;

        core(n , 0, board, ans);

        return ans;
    }
};
