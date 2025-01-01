class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return 0;

        int jumps = 0, i = 0, jm, score, idx;
        bool reached = 0;

        while (!reached) {

            jm = nums[i];
            score = 0;

            for (int j = 1; j <= jm; j++) {

                if (i + j < n - 1) {
                    if (nums[i + j] - (jm - j) >= score) {
                        score = nums[i + j] - (jm - j);
                        idx = i + j;
                    }
                }
                else {
                    reached = 1;
                }
            }

            i = idx;

            ++jumps;

        }

        return jumps;

    }
};