class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(3, vector<int>(n+1, 0));

        for(int i = n-1; i >= 0; --i){
            int v = nums[i];
            dp[0][i] = dp[0][i+1];
            dp[1][i] = dp[1][i+1];
            dp[2][i] = dp[2][i+1];

            for(int j = 0; j < 3; ++j){
                int sum = v + dp[j][i+1];

                if(sum%3 == 0){
                    dp[0][i] = max(dp[0][i], sum);
                }
                else if(sum%3 == 1){
                    dp[1][i] = max(dp[1][i], sum);;
                }
                else{
                    dp[2][i] = max(dp[2][i], sum);;
                }
            }
        }

        return dp[0][0];
    }
};