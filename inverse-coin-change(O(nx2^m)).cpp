// TLE
// TC - O(n * 2^m) and
// SC - O(m + n).
// n = numWays.size() , m = number of denominations.

class Solution {
public:
    vector<int> denoms_;

    void count_num_ways(int amount, int curr, int i, int& num_of_ways) {
        if (curr > amount) return;

        if (curr == amount) {
            ++num_of_ways;
            return;
        }

        if (i == denoms_.size()) return;

        count_num_ways(amount, curr + denoms_[i], i, num_of_ways);

        count_num_ways(amount, curr, i + 1, num_of_ways);
    }

    vector<int> findCoins(vector<int>& numWays) {

        int n = numWays.size(); 
        cout << n ; 
        denoms_.clear();

        for (int i = 0; i < n; ++i) {
            int amount = i+1 ; 
            int num_of_ways = 0;

            count_num_ways(amount, 0, 0, num_of_ways);

            if(!(num_of_ways == numWays[i] || num_of_ways == (numWays[i] - 1))){
                return vector<int>();
            }

            if (num_of_ways + 1 == numWays[i]) {
                denoms_.push_back(amount);
            }
        }

        sort(denoms_.begin(), denoms_.end());
        return denoms_;
    }
};
