//time limit exceed

class Solution {
public:

    vector<int> nums_;
    long long c = 0;
    int n_;

    bool isSpecial(int p, int q, int r, int s) {

        if (q - p > 1 && r - q > 1 && s - r > 1) {
            if (nums_[p] * nums_[r] == nums_[q] * nums_[s]) {
                return true;
            }
        }

        return false;

    }

    void fun(int p, int q, int r, int s) {

        if (s != -1) {
            if (isSpecial(p, q, r, s)) {
                ++c;
            }
        }
        else if (r != -1) {
            for (int i = r + 1; i < n_; i++) {
                fun(p, q, r, i);
            }
        }
        else if (q != -1) {
            for (int i = q + 1; i < n_; i++) {
                fun(p, q, i, -1);
            }
        }
        else if (p != -1) {
            for (int i = p + 1; i < n_; i++) {
                fun(p, i, -1, -1);
            }
        }
        else {
            for (int i = 0; i < n_; i++) {
                fun(i, -1, -1, -1);
            }
        }

        return;

    }

    long long numberOfSubsequences(vector<int>& nums) {

        nums_ = nums;
        c = 0;
        n_ = nums.size();

        fun(-1, -1, -1, -1);

        return c;

    }
};