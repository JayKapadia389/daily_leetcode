// Used 0-1 knapsack DP with memoization.

class Solution {
private:
    int x_ , mod_;
    vector<vector<int>> memo;

    long long recc(long long target, int n){
        if(target == 0){
            return 1;
        }
        if(target < 0){
            return 0;
        }
        if(n == 0){
            return 0;
        }

        if(memo[target][n] != -1){
            return memo[target][n];
        }

        return (memo[target][n] = (recc(target - pow(n,x_), n-1) + recc(target, n-1)) % mod_);
    }

public:
    int numberOfWays(int n, int x) {
        x_ = x;
        mod_ = 1e9 + 7;
        memo = vector<vector<int>>(n+1, vector<int>(n+1, -1));

        recc(n, n);
        return memo[n][n];
    }
};