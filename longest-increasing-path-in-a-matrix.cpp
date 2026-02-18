// Solution 1: Top-down 2D DP with memoization
class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<vector<int>> dp;

    int dfs(int i, int j, int m, int n, const vector<vector<int>>& matrix) {
        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int mx = 0;

        for (const auto& d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x < m && y >= 0 && y < n &&
                matrix[x][y] > matrix[i][j]) {
                mx = max(mx, dfs(x, y, m, n, matrix));
            }
        }

        return (dp[i][j] = (mx + 1));
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        int ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dfs(i, j, m, n, matrix));
            }
        }

        return ans;
    }
};