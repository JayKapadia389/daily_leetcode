// Solution 1:
// O(nlogn)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        sort(nums.begin() + 1, nums.end());
        return nums[0] + nums[1] + nums[2];
    }
};

// Solution 2:
// O(n)
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2){
                min2 = nums[i];
            }
        }

        return nums[0] + min1 + min2;
    }
};
