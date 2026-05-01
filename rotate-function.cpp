class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        long long ans = INT_MIN, candidate = 0;
        long long total = 0;
        int n = nums.size();

        for(int i = 0; i < n; ++i){
            candidate += (i * nums[i]);
            total += nums[i];
        }

        ans = max(ans, candidate);

        for(int i = 1; i < n; ++i){
            candidate += total;
            candidate -= (n * nums[n - i]);
            ans = max(ans, candidate);
        }

        return ans;
    }
};