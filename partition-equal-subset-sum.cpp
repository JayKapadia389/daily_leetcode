class Solution {
private:
    bool recc(int idx, int target, vector<vector<int>>& dp, vector<int>& nums){
        if(idx == -1){
            return false;
        }

        if(target == nums[idx]){
            return true;
        }

        if(target < 0){
            return false;
        }

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        return dp[idx][target] = (recc(idx-1, target, dp, nums) || recc(idx-1, target-nums[idx], dp, nums));
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), m = 0, target ;

        for(auto num : nums){
            m+=num;
        }

        if(m % 2 != 0){
            return false;
        }
        target = m/2;

        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return recc(n-1, target, dp, nums);
    }
};