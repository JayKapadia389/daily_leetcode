class Solution {
public:
    int max_or_, cnt;

    void fun(int curr, vector<int>& nums, bool consider_curr, int orr){
        if(consider_curr){
            orr = orr | nums[curr];
        }
        if(curr == nums.size()-1){
            if(orr == max_or_){
                ++cnt;
            }
            return;
        }
        fun(curr+1,nums,0,orr);
        fun(curr+1,nums,1,orr);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        max_or_ = 0;
        cnt = 0;

        // or-ing all values gives the maximum or value.
        for(auto i : nums){
            max_or_|=i;
        }

        fun(0,nums,0,0);
        fun(0,nums,1,0);
        return cnt;
    }
};