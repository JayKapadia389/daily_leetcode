// Space-optimized bottom-up 2D-DP
const int OFFSET = 1000; 

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> prev(2001, 0);
        vector<int> curr(2001, 0);
        prev[target + OFFSET] = 1;
        
        for(int i = n-1; i >= 0; --i){
            for(int j = 0; j < 2001; ++j){
                int l = j - nums[i], r = j + nums[i];
                curr[j] = ((l < 0)? 0 : prev[l]) + ((r >= 2001)? 0 : prev[r]);
            }

            prev = curr;
        }

        return curr[0 + OFFSET];
    }
};