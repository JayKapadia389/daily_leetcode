class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int right = 0, left = 0, ans = 0;
        for(auto num : nums){
            right += num;
        }

        for(int i = 0; i < nums.size()-1; ++i){
            left += nums[i];
            right -= nums[i];

            if((left - right)%2 == 0){
                ++ans;
            }
        }

        return ans;
    }
};