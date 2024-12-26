class Solution {
public:

    int count_, n_, target_;
    vector<int> nums_;

    void fun(int acc, int idx) {

        if (idx == n_) {
            if (acc == target_) {
                ++count_;
            }
        }
        else {

            fun(acc + nums_[idx], idx + 1);
            fun(acc - nums_[idx], idx + 1);

        }

        return;

    }

    int findTargetSumWays(vector<int>& nums, int target) {

        count_ = 0;
        n_ = nums.size();
        nums_ = nums;
        target_ = target;

        fun(0, 0);

        return count_;

    }
};