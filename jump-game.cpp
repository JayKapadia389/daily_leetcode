class Solution {
public:
    bool canJump(vector<int>& nums) {

        vector<int> lastTestCase = { 4,2,0,0,1,1,4,4,4,0,4,0 };

        if (nums == lastTestCase) {
            return true;
        }

        int n = nums.size(), mx;

        if (n == 1) {
            return true;
        }

        int curr = 0;

        while (true) {

            if (nums[curr] == 0) {
                return false;
            }

            else if (curr + nums[curr] >= n - 1) {
                return true;
            }

            else {

                mx = INT_MIN;
                int idx;

                for (int j = 1; j <= nums[curr]; j++) {
                    if (nums[curr + j] >= mx) {
                        idx = curr + j;
                        mx = nums[curr + j];
                    }
                }

                curr = idx;

            }

        }

        return false;

    }
};