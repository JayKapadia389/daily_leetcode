class Solution {
public:
    long long countBadPairs(vector<int>& nums) {

        long long n = nums.size();

        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] - i;
        }

        map<int, long> freqs;

        for (auto i : nums) {
            ++freqs[i];
        }

        long long goodpairs = 0;

        for (auto [num, freq] : freqs) {
            if (freq > 1) {
                goodpairs += (freq * (freq - 1) / 2);
            }
        }

        cout << "goodpairs:" << goodpairs;

        return (n * (n - 1) / 2) - goodpairs;

    }
};