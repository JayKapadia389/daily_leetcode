class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int len = INT_MIN;
        int l = 0, r = 0;
        bool z = 0;
        int n = nums.size();

        while(r < n){
            if(nums[r] == 0){
                if(z){
                    while(nums[l] != 0){
                        ++l;
                    }
                    ++l;
                }
                else{
                    z = 1;
                }
            }

            len = max(len , r - l);
            ++r;
        }

        return len; 
    }
};