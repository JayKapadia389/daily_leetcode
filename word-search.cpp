class Solution {
public:
    bool isValid(map<pair<int, int>, bool> mp, int i, int j, int pi, int pj,
                 int m, int n) {

        if (!mp[{i, j}] && (i < n && i >= 0) && (j < m && j >= 0) &&
            !(i == pi && j == pj)) {
            return true;
        }
        return false;
    }

    bool recc(map<pair<int, int>, bool>& mp, vector<vector<char>>& board, int n,
              int m, int i, int j, string word, int e, int pi, int pj) {
        cout << i << " " << j << endl ;
        
        if (board[i][j] != word[e]) {
            return false;
        }


        if (e + 1 == word.length()) {
            cout << "end " << i << j ; 
            return true;
        }

        if (isValid(mp, i - 1, j, pi, pj, m, n)) {

            // map 1
            mp[{i - 1, j}] = 1;
            if (recc(mp, board, n, m, i - 1, j, word, e + 1, i, j)) {
                return true;
            }

            // map 0
            mp[{i - 1, j}] = 0;
        }

        if (isValid(mp, i + 1, j, pi, pj, m, n)) {
            mp[{i + 1, j}] = 1;

            if (recc(mp, board, n, m, i + 1, j, word, e + 1, i, j)) {
                return true;
            }
            mp[{i + 1, j}] = 0;
        }

        if (isValid(mp, i, j - 1, pi, pj, m, n)) {
            mp[{i, j - 1}] = 0;

            if (recc(mp, board, n, m, i, j - 1, word, e + 1, i, j)) {
                return true;
            }
            mp[{i, j - 1}] = 1;
        }

        if (isValid(mp, i, j + 1, pi, pj, m, n)) {
            mp[{i, j + 1}] = 0;

            if (recc(mp, board, n, m, i, j + 1, word, e + 1, i, j)) {
                return true;
            }
            mp[{i, j + 1}] = 1;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int n = board.size();
        int m = board[0].size();
        map<pair<int, int>, bool> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (recc(mp, board, n, m, i, j, word, 0, -1, -1)) {
                    return true;
                }
            }
        }

        return false;
    }
};