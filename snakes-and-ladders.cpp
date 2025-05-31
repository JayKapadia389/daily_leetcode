class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board[0].size();
        int n_sq = n * n;

        vector<int> vec(n_sq + 1, 0);
        int iter = 1;
        vector<bool> visited(n_sq + 1, 0);

        bool leftToRight = true;
        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j) {
                    vec[iter++] = board[i][j];
                }
            }
            else {
                for (int j = n - 1; j >= 0; --j) {
                    vec[iter++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }


        int count = 0;

        queue<int> q;
        q.push(1);
        visited[1] = 1;
        q.push(0);

        while (q.front() != 0) {
            ++count;

            while (q.front() != 0) {

                int curr = q.front(); q.pop();

                for (int k = curr + 1; k <= curr + 6 && k <= n_sq; ++k) {
                    int next = k;

                    if (vec[next] != -1)
                        next = vec[next];

                    if (next == n * n) {
                        return count;
                    }

                    if (visited[next] == 0) {
                        q.push(next);
                        visited[next] = 1;
                    }
                }

            }

            q.pop();
            q.push(0);

        }

        return -1;

    }
};