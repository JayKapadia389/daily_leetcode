class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int mx_len = 1;
        int l = 0, r = 0;

        sort(nums.begin() , nums.end());

        while(r != nums.size()){
            if((static_cast<float>(nums[r]) / nums[l]) <= k){
                mx_len = max(mx_len , r-l+1);
                ++r;
            }
            else{
                ++l;
            }
        }

        return (nums.size() - mx_len);
    }
};