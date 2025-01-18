class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {

        int diff = INT_MIN;

        for (int i = 0; i < nums.size() - 1; i++) {
            diff = max(diff, abs(nums[i] - nums[i + 1]));
        }

        diff = max(diff, abs(nums[nums.size() - 1] - nums[0]));

        return diff;
    }
};