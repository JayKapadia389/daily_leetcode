class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {

        int ans = INT_MIN, currSum = 0, n = nums.size();
        currSum = nums[0];
        ans = currSum;

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                currSum += nums[i];
                ans = max(ans, currSum);
            }
            else {
                currSum = nums[i];
            }
        }

        return ans;

    }
};