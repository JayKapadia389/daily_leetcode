class Solution {
public:
    long long mod = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<int> prev(26, 0), next(26, 0);

        for (char ch : s) {
            ++prev[ch - 'a'];
        }

        for (int i = 0; i < t; ++i) {
            for (int j = 0; j < 25; ++j) {
                next[j + 1] = prev[j];
            }

            next[0] = (next[0] + prev[25]) % mod;
            next[1] = (next[1] + prev[25]) % mod;

            prev = move(next);
            next = vector<int>(26, 0); // Fix: Reinitialize next
        }

        long long ans = 0;
        for (int count : prev) {
            ans = (ans + count) % mod;
        }

        return ans;
    }
};
