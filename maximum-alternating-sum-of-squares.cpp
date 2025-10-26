class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto& num : nums){
            if(num < 0){
                num *= -1;
            }
        }

        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size(); 
        int limit = n%2 == 0 ? n/2 - 1 : n/2;
        long long ans = 0;

        for(int i = 0; i <= limit; ++i){
            ans += (static_cast<long long>(nums[i]) * nums[i]);
        }

        for(int i = limit + 1; i < n; ++i){
            ans -= (static_cast<long long>(nums[i]) * nums[i]);
        }

        return ans;
    }
};