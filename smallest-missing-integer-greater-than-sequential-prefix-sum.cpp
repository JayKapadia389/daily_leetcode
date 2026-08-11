class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0], n = nums.size();

        int i = 1;
        for(; i < n; ++i){
            if(nums[i] == (nums[i - 1] + 1)){
                sum += nums[i];
            }
            else {
                break;
            }
        }

        sort(nums.begin() + i, nums.end());

        int missing = sum;
        --i;
        for(; i < n; ++i){
            if(nums[i] == missing){
                ++missing;
            }
        }

        return missing;
    }
};