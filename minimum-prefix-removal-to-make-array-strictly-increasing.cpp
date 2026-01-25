class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size(), i = nums.size()-2;
        while(i >= 0 && nums[i] < nums[i+1]){
            --i;
        }
        return i+1;
    }
};