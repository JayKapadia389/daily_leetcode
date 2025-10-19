class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int cnt = 1, n = nums.size();

        sort(nums.begin() ,nums.end());

        nums[0] -= k;
        for(int i = 1; i < n; ++i){
            nums[i] = min(nums[i]+k, max(nums[i]-k, nums[i-1] + 1));
            if(nums[i] != nums[i-1]){
                ++cnt;
            }
        }

        return cnt;
    }
};