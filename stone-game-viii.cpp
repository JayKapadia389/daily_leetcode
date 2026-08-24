class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix_sum(n);
        vector<int> dp(n);

        prefix_sum[0] = stones[0];
        for(int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + stones[i];
        }

        dp[n - 2] = prefix_sum[n - 1];
        for(int i = n - 3; i >= 0; --i) {
            dp[i] = max(dp[i + 1], prefix_sum[i + 1] - dp[i + 1]);
        }

        return dp[0];
    }
};