class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        long long right = 0, left = 0;
        int n = nums.size();

        for (auto i : nums) {
            right += i;
        }

        left += nums[0];
        right -= nums[0];

        int c = 0;

        for (int i = 0; i < n - 1; i++) {
            if (left >= right) {
                ++c;
            }

            left += nums[i + 1];
            right -= nums[i + 1];
        }

        return c;

    }
};