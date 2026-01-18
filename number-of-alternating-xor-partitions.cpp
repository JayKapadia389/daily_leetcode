class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        const int MOD = 1e9 + 7;
        vector<int> dp(4, 0);
        vector<int> pre_dp(4, 0);
        vector<int> state = {0, target1, target1^target2, target2};
        int prefix = 0;
        int n = nums.size();
        int total = 0;

        dp[0] = 1;
        pre_dp[0] = 1;

        for(int i = 0; i < n; ++i){
            prefix ^= nums[i];
            if(i == n-1){
                for(int j = 0; j < 4; ++j){
                    if(prefix == state[j])
                        total = (total + pre_dp[(j+3)%4])%MOD;
                }
            }
            
            for(int j = 0; j < 4; ++j){
                if(prefix == state[j])
                    dp[j] = (dp[j] + pre_dp[(j+3)%4])%MOD;
            }
            pre_dp = dp;
        }
        return total;
    }
};