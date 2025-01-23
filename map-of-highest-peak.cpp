class Solution {
public:

    int m_, n_;

    bool isValid(int X, int Y) {
        if (X < 0 || X >= m_ || Y < 0 || Y >= n_)
            return false;

        return true;
    }

    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {

        m_ = isWater.size(), n_ = isWater[0].size();

        vector<vector<int>> dir = {
            {-1,0},
            {0,1},
            {1,0},
            {0,-1},
        };

        vector<vector<int>> height(m_, vector<int>(n_, 0));
        vector<vector<int>> visited(m_, vector<int>(n_, 0));

        queue<pair<int, int>> q;

        for (int i = 0; i < m_; i++) {
            for (int j = 0; j < n_; j++) {
                if (isWater[i][j]) {
                    visited[i][j] = 1;
                    q.push({ i,j });
                }
            }
        }

        //parallel-bfs
        pair<int, int> p;
        int x, y, X, Y;

        while (!q.empty()) {
            p = q.front();
            x = p.first;
            y = p.second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                X = x + dir[i][0];
                Y = y + dir[i][1];

                if (isValid(X, Y) && !visited[X][Y]) {
                    visited[X][Y] = 1;
                    q.push({ X,Y });
                    height[X][Y] = height[x][y] + 1;
                }

            }
        }

        return height;
    }
};