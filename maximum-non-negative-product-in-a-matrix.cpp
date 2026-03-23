int MOD = 1e9 + 7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<pair<long, long>>> dp(m, vector<pair<long, long>>(n));

        dp[0][0].first = dp[0][0].second = grid[0][0];

        for(int i = 1; i < m; ++i){
            dp[i][0].first = dp[i][0].second = dp[i-1][0].first * grid[i][0]; 
        }

        for(int j = 1; j < n; ++j){
            dp[0][j].first = dp[0][j].second = dp[0][j-1].first * grid[0][j]; 
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(grid[i][j] >= 0){
                    dp[i][j].first = min(dp[i-1][j].first, dp[i][j-1].first) * grid[i][j];
                    dp[i][j].second = max(dp[i-1][j].second, dp[i][j-1].second) * grid[i][j];
                }
                else{
                    dp[i][j].first = max(dp[i-1][j].second, dp[i][j-1].second) * grid[i][j];
                    dp[i][j].second = min(dp[i-1][j].first, dp[i][j-1].first) * grid[i][j];
                }
            }
        }

        if(dp[m-1][n-1].second < 0){
            return -1; 
        }
        return dp[m-1][n-1].second % MOD;
    }
};