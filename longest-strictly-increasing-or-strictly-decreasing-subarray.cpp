class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {

        int ans = 1, currLen = 1, n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                ++currLen;
                ans = max(ans, currLen);
            }
            else {
                currLen = 1;
            }
        }

        currLen = 1;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                ++currLen;
                ans = max(ans, currLen);
            }
            else {
                currLen = 1;
            }
        }

        return ans;

    }
};