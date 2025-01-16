class Solution {
public:

    void XOR(int& result, int i) {
        result ^= i;
    }

    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size(), m = nums2.size();

        int result = 0;

        if (n % 2 != 0) {
            for (auto i : nums2) {
                // loop on second array and xor it with result
                XOR(result, i);
            }
        }
        if (m % 2 != 0) {
            for (auto i : nums1) {
                // loop on first array and xor it with result
                XOR(result, i);
            }
        }

        return result;

    }
};