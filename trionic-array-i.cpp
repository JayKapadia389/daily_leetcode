// Solution 1: with boolean 
//
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums[0] >= nums[1]){
            return false;
        }

        bool up = 1;
        int switches = 0;
        for(int i = 2; i < nums.size(); ++i){
            if(nums[i] == nums[i-1]){
                return false;
            }

            if((up && (nums[i] < nums[i-1])) || (!up && (nums[i] > nums[i-1]))){
                ++switches;
                up = !up;
            }
        }

        return (switches == 2);
    }
};

// Solution 2: without boolean 
//
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if (nums[0] >= nums[1]) {
            return false;
        }

        int switches = 0;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i - 1] == nums[i]) {
                return false;
            }
            if ((nums[i - 2] - nums[i - 1]) * (nums[i - 1] - nums[i]) < 0) {
                switches++;
            }
        }
        return (switches == 2);
    }
};