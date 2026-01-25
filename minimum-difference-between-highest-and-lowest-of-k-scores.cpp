class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mn = INT_MAX;
        for(int i = 0; (i+k) <= nums.size(); ++i){
            mn = min(mn, abs(nums[i] - nums[i+k-1]));
        }
        return mn;
    }
};