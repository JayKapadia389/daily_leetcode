class Solution {
public:
    int countCommas(int n) {
        int t_c = 0, i = 1, nums = 9;

        while(n != 0) {
            int nums_with_i_digits = min(nums, n);
            n -= nums_with_i_digits;
            int comma_per_number = (i / 3) - ((i % 3 == 0) ? 1 : 0);
            t_c += (comma_per_number * nums_with_i_digits);
            i += 1;
            nums *= 10;
        }

        return t_c;
    }
};