class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k+1, INT_MIN)));
        dp[0][0][0] = 0;

        for(int c = 0; c <= k; ++c){
            for(int i = 0; i < m; ++i){
                for(int j = 0; j < n; ++j){
                    if(grid[i][j] == 1 || grid[i][j] == 2){
                        if(c != 0){
                            dp[i][j][c] = max((i-1 >= 0)? dp[i-1][j][c-1] : INT_MIN, (j-1 >= 0)? dp[i][j-1][c-1] : INT_MIN);
                            dp[i][j][c] += ((dp[i][j][c] == INT_MIN) ? 0 : grid[i][j]);
                        }
                    }
                    else{
                        if(!(i == 0 && j == 0)){
                            dp[i][j][c] = max((i-1 >= 0)? dp[i-1][j][c] : INT_MIN,  (j-1 >= 0)? dp[i][j-1][c] : INT_MIN);
                        }
                    }
                }
            }
        }

        int ans = INT_MIN;
        for(int c = 0; c <= k; ++c){
            ans = max(ans, dp[m-1][n-1][c]);
        }
        return (ans == INT_MIN) ? -1 : ans;
    }
};