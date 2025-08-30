class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;

        //rows
        for(int i = 0; i < 9; ++i){
            s.clear();
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j]) == s.end()) 
                        s.insert(board[i][j]);
                    else
                        return false;
                }
            }
        }

        //column
        for(int j = 0; j < 9; ++j){
            s.clear();
            for(int i = 0; i < 9; ++i){
                if(board[i][j] != '.'){
                    if(s.find(board[i][j]) == s.end())
                        s.insert(board[i][j]);
                    else
                        return false;
                }
            }
        }

        // sub-grid
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+=3){
                s.clear();
                for(int x = 0; x < 3; ++x){
                    for(int y = 0; y < 3; ++y){
                        if(board[i+x][j+y] != '.'){
                                if(s.find(board[i+x][j+y]) == s.end())
                                    s.insert(board[i+x][j+y]);
                                else
                                    return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};