class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(31, n);
        int mx_and = 0;
        int ans_len = 0;

        for(int i = n-1; i >= 0; --i){
            int recent_zero = n;
            int mask = 1;
            for(int j=0; j<31; ++j){
                if(nums[i] & mask){
                    recent_zero = min(recent_zero, pos[j]);
                }
                else{
                    pos[j] = i;
                }
                mask<<=1;
            }
            if(nums[i] == mx_and){
                ans_len = max(ans_len, recent_zero - i);
            }
            else if(nums[i] > mx_and){
                mx_and = nums[i];
                ans_len = recent_zero - i;
            }
        }

        return ans_len;
    }
};