class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {

        int n = nums.size();

        vector<int> ans(n);

        int acc = 0, k = 0, twoPower = 1, bit;

        for (int i = 0; i < n; i++) {

            acc = (acc & ~(nums[i])) | (~acc & (nums[i]));

            twoPower = 1, k = 0, bit = 1;

            for (int j = 0; j < maximumBit; j++) {

                if ((acc & bit) == 0) {
                    k += twoPower;
                }

                bit <<= 1;
                twoPower *= 2;

            }

            ans[n - 1 - i] = k;
        }

        return ans;
    }
};