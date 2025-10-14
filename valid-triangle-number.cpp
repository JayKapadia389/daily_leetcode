class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n - 2; ++i){
            for(int j = i+1; j < n-1; ++j){
                int sum = nums[i] + nums[j];
                auto it = std::upper_bound(nums.begin() + j + 1, nums.end(), sum - 1);
                ans += (it - (nums.begin() + j) - 1);
            }
        }

        return ans;
    }
};