class Solution {
private:
    int m_, n_;
    vector<vector<bool>> visited_;
    vector<vector<int>> dir_;

    bool dfs(int i, int j, int prev_i, int prev_j, char ch,
             vector<vector<char>>& grid) {
        if (visited_[i][j]) {
            return true;
        }

        visited_[i][j] = 1;

        for (auto d : dir_) {
            int new_i = i + d[0];
            int new_j = j + d[1];

            if ((new_i >= 0 && new_i < m_ && new_j >= 0 && new_j < n_) &&
                (grid[new_i][new_j] == ch) &&
                !(new_i == prev_i && new_j == prev_j) &&
                dfs(new_i, new_j, i, j, ch, grid)) {
                    return true;
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        m_ = grid.size();
        n_ = grid[0].size();
        visited_ = vector<vector<bool>>(m_, vector<bool>(n_, 0));
        dir_ = {
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0},
        };

        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (visited_[i][j] == 0 && dfs(i, j, -1, -1, grid[i][j], grid)) {
                    return true;
                }
            }
        }

        return false;
    }
};