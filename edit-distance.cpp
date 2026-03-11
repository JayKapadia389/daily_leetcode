class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        for(int i = 0; i <= m; ++i){
            dp[i][n] = m - i;
        }

        for(int j = 0; j <= n; ++j){
            dp[m][j] = n - j;
        }

        for(int i = m - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                dp[i][j] = (word1[i] == word2[j])? dp[i+1][j+1] : min({
                    dp[i+1][j] + 1,
                    dp[i][j+1] + 1,
                    dp[i+1][j+1] + 1
                });
            }
        }

        return dp[0][0];
    }
};