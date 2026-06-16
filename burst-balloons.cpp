class Solution {
private:
int recc(int l, int r, vector<int>& nums, const int& n, vector<vector<int>>& dp) {
    if(r < l) return 0;

    if(dp[l][r] != -1){
        return dp[l][r];
    }

    int ans = INT_MIN, multiplier;
    multiplier = (l == 0)? 1 : nums[l - 1];
    multiplier *= (r + 1 == n)? 1 : nums[r + 1];

    for(int i = l; i <= r; ++i){
        int me = nums[i];
        me *= multiplier;
        int left_side = recc(l, i - 1, nums, n, dp);
        int right_side = recc(i + 1, r, nums, n, dp);
        ans = max(ans, me + left_side + right_side);
    }

    return dp[l][r] = ans;
}

public:
    int maxCoins(vector<int>& nums) {
        int ans = INT_MIN, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return recc(0, n - 1, nums, nums.size(), dp);
    }
};