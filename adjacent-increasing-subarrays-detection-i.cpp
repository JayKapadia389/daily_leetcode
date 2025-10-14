class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i <= n - (2*k); ++i){
            bool found = 1;
            for(int j = 1; j < k; ++j){
                if(!((nums[i+j] > nums[i+j-1]) && (nums[i+k+j] > nums[i+k+j-1]))){
                    found = 0;
                    break;
                }
            }
            if(found){
                return true;
            }
        }
        return false;
    }
};