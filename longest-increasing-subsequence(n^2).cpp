class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        int ans = 1;
        vector<int> dp(nums.size());

        for(int i = 0; i < nums.size(); ++i){
            int temp = 0; 
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    temp = max(temp, dp[j]);
                }
            }
            dp[i] = temp + 1;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};