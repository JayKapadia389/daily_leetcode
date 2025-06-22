class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        int n = static_cast<int>(numWays.size());
    std::vector<long long> myWays(n + 1, 0);
    myWays[0] = 1;

    std::vector<int> res;

    for (int i = 1; i <= n; ++i) {
        if (myWays[i] == numWays[i - 1]) continue;

        if (numWays[i - 1] - myWays[i] == 1) {
            res.push_back(i);
            for (int j = i; j <= n; ++j) {
                myWays[j] += myWays[j - i];
            }

        } else {
            return {};
        }
    }
    return res;
    }
};