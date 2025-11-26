class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), mod = 1e9 + 7;;
        vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(k, 0)));

        int last = grid[m-1][n-1];

        dp[m-1][n-1][last%k] = 1;

        for(int i = m-1; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                int rem = grid[i][j] % k;

                // from right
                for(int p = 0; p < k; ++p){
                    dp[i][j][(rem + p) % k] += dp[i][j+1][p];
                }

                // from bottom
                for(int p = 0; p < k; ++p){
                    dp[i][j][(rem + p) % k] = (dp[i][j][(rem + p) % k] + dp[i+1][j][p]) % mod;
                }
            }
        }

        return dp[0][0][0];
    }
};