class Solution {

private:

    int ncr(int n) {
        return n * (n - 1) / 2;
    }

public:

    int tupleSameProduct(vector<int>& nums) {

        map<int, int> freq;
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ++freq[nums[i] * nums[j]];
            }
        }

        int ans = 0;

        for (auto i : freq) {

            if (i.second >= 2) {
                ans += (8 * ncr(i.second));
            }

        }

        return ans;

    }
};