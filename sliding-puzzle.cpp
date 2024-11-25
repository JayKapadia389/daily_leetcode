class Solution {
public:

    //dir 
    vector<vector<int>> dir = {
        {-1 , 0},
        {0 , 1},
        {1 , 0},
        {0 , -1},
    };

    //isAns
    bool isAns(vector<vector<int>> v) {

        if (v[0][0] == 1 && v[0][1] == 2 && v[0][2] == 3 && v[1][0] == 4 && v[1][1] == 5 && v[1][2] == 0) {
            return true;
        }
        return false;

    }

    //swap
    void swap(vector<vector<int>>& board, int I, int J, int X, int Y) {

        int temp = board[I][J];
        board[I][J] = board[X][Y];
        board[X][Y] = temp;

    }

    int slidingPuzzle(vector<vector<int>>& board) {

        queue<vector<vector<int>>> q;
        map<vector<vector<int>>, bool> m;

        int ans = 0, I, J, X, Y;

        q.push(board);
        q.push(NULL);

        vector<vector<int>> curr;

        while (true) {

            curr = q.top();
            q.pop();

            if (curr == NULL) {
                if (q.empty()) {
                    return -1;
                }
                else {
                    q.push(NULL);
                    ++ans;
                }
            }
            else {

                if (isAns(curr)) {
                    return ans;
                }
                else {// dfs: explore neighbours

                    for (int i = 0; i < 2; i++) {
                        for (int j = 0; j < 3; j++) {
                            if (curr[i][j] == 0) {
                                I = i;
                                J = j;
                            }
                        }
                    }

                    for (int i = 0; i < 4; i++) {
                        X = I + dir[i][0];
                        Y = J + dir[i][1];

                        if (
                            !(X < 0 || X >= 2 || Y < 0 || Y >= 3)
                            ) {
                            swap(curr, I, J, X, Y);

                            if (!m[curr]) {
                                m[curr] = 1;
                                q.push(curr);
                            }

                            swap(curr, I, J, X, Y);
                        }
                    }

                }

            }

        } // while

        return ans;

    }
};