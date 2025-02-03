class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {

        int n = nums.size();

        if (n == 1) {
            return true;
        }

        int add = nums[0] + nums[1];
        if ((add % 2) == 0) {
            return false;
        }

        for (int i = 1; i < n - 1; i++) {
            add -= nums[i - 1];
            add += nums[i + 1];

            if ((add % 2) == 0)
                return false;
        }

        return true;

    }
};