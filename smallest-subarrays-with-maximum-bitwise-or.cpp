class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {

        int n = nums.size();
        vector<int> pos(31, -1);
        vector<int> ans(n);

        for(int i = n-1; i>=0; --i){
            int num = nums[i];
            int mask = 1;

            for(int j = 0; j < 31; ++j){
                bool bit = num & mask;
                if(bit){
                    pos[j] = i;
                }
                mask<<=1;
            }

            int mx_pos = INT_MIN;
            for(int i = 0; i<31; ++i){
                mx_pos = max(mx_pos, pos[i]);
            }
            if(mx_pos == -1){
                ans[i] = 1;
            }
            else{
                ans[i] = mx_pos - i +1 ;
            }
        }

        return ans;
    }
};