class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int switches = 0, j = INT_MAX-1;
        bool up = 0;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != nums[0]){
                j = i;
                up = nums[i] > nums[0];
                break;
            }
        } 

        for(int i = j+1 ; i < nums.size(); ++i){
            if(nums[i] < nums[i-1] && up){
                ++switches;
                up = 0;
            }
            else if(nums[i] > nums[i-1] && !up){
                ++switches;
                up = 1;
            }
        }

        return switches;
    }
};