class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3)));

        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = dp[0][0][2] = max(0, coins[0][0]);

        for(int i = 1; i < m; ++i){
            for(int k = 0; k < 3; ++k){
                if(k == 0){
                    dp[i][0][k] = dp[i-1][0][k] + coins[i][0]; 
                }
                else{
                    dp[i][0][k] = max(dp[i-1][0][k] + coins[i][0], dp[i-1][0][k-1]); 
                }
            }
        }

        for(int j = 1; j < n; ++j){
            for(int k = 0; k < 3; ++k){
                if(k == 0){
                    dp[0][j][k] = dp[0][j-1][k] + coins[0][j]; 
                }
                else{
                    dp[0][j][k] = max(dp[0][j-1][k] + coins[0][j], dp[0][j-1][k-1]); 
                }
            }
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                for(int k = 0; k < 3; ++k){
                    if(k == 0){
                        dp[i][j][k] = max(dp[i-1][j][k] + coins[i][j], dp[i][j-1][k] + coins[i][j]); 
                    }
                    else{
                        dp[i][j][k] = max({
                            dp[i-1][j][k] + coins[i][j],
                            dp[i][j-1][k] + coins[i][j], 
                            dp[i][j-1][k-1],
                            dp[i-1][j][k-1],
                        }); 
                    }
                }
            }
        }

        return dp[m-1][n-1][2];
    }
};