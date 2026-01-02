//My solution - O(n) time and space
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> suffixMin(n);

        suffixMin[n-1] = INT_MAX;
        for(int i = n - 2; i >= 0; --i){
            suffixMin[i] = min(suffixMin[i+1], nums[i+1]); 
        }

        long long score = LLONG_MIN, sum = 0;
        for(int i = 0; i < n-1; ++i){
            sum += nums[i];
            score = max(score, sum - suffixMin[i]);
        }
        return score;
    }
};

// O(1) space
class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long ans = nums[0] - nums[1], prefix_sum = 0;
        int n = nums.size(), Min = nums[n - 1];
        for(int i = 0; i < n - 1; i++) prefix_sum += nums[i];
        for(int i = n - 2; i >= 0; i--) {
            ans = max(ans, prefix_sum - Min);
            Min = min(Min, nums[i]);
            prefix_sum -= nums[i];
        }
        return ans;
    }
};