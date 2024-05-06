class Solution {
public:

    int dc[4] = {1,-1,0,0} ;
    int dr[4] = {0,0,-1,1} ;
    bool isValid( int i, int j, int m, int n) {

        if ((i < n && i >= 0) && (j < m && j >= 0)) {
            return true;
        }
        return false;
    }

    bool recc(map<pair<int, int>, bool>& mp, vector<vector<char>>& board, int n,
              int m, int i, int j, string word, int e) {

        if(mp[{i,j}]){
            return false ;
        }

        if (board[i][j] != word[e]) {
            return false;
        }

        if (e + 1 == word.length()) {
            return true;
        }

        mp[{i,j}] = 1 ;

        for(int x = 0 ; x < 4 ; x++){

            if (isValid(i + dc[x], j + dr[x], m, n)) {

                if (recc(mp, board, n, m,i + dc[x], j + dr[x], word, e + 1)) {
                    return true;
                }

            }

        }

        mp[{i,j}] =0 ;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();
        map<pair<int, int>, bool> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (recc(mp, board, n, m, i, j, word, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};