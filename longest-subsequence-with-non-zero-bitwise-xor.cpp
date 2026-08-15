class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        bool non_zero_exists = false;
        int xr = 0, n = nums.size();

        for(auto num : nums) {
            if(num != 0) non_zero_exists = true;
            xr ^= num;
        }

        if(!non_zero_exists) {
            return 0;
        }

        return (xr == 0) ? n - 1 : n; 
    }
};