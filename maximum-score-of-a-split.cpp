class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefixSum(n);
        vector<int> suffixMin(n);

        prefixSum[0] = nums[0];
        for(int i = 1; i < n; ++i){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        suffixMin[n-1] = INT_MAX;
        for(int i = n - 2; i >= 0; --i){
            suffixMin[i] = min(suffixMin[i+1], nums[i+1]); 
        }

        long long score = LLONG_MIN;
        for(int i = 0; i < n-1; ++i){
            score = max(score, prefixSum[i] - suffixMin[i]);
        }
        return score;
    }
};