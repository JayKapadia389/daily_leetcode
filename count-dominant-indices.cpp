// contest
// optimal 
// O(n) time - single pass
// O(1) space
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size(), dom_cnt = 0;
        int sum = nums[n-1];

        for(int i = n-2; i >= 0; --i){
            if(nums[i] > (sum/(n - i - 1))){
                ++dom_cnt;
            }
            sum += nums[i];
        }

        return dom_cnt;
    }
};