class Solution {
public:
    bool check(vector<int>& nums) {

        int c = 0, n = nums.size();

        if (n == 1) {
            return true;
        }

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                ++c;
            }
        }

        if (c == 0 || (c == 1 && nums[n - 1] <= nums[0])) {
            return true;
        }
        return false;

    }
};