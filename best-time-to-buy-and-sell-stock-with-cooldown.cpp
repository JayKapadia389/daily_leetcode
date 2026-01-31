// Solution 1:
// Top-down DP (memo)
class Solution {
private:
    vector<vector<int>> dp;

    int recc(vector<int>& prices, int n, int idx, bool bought){
        if(idx >= n){
            return 0;
        }

        if(dp[idx][bought] != -1){
            return dp[idx][bought];
        }

        if(bought){
            dp[idx][bought] = max(
                0 + recc(prices, n, idx + 1, bought),           // hold
                prices[idx] + recc(prices, n, idx + 2, !bought) // sell + cooldown
            );
        }
        else{
            dp[idx][bought] = max(
                0 + recc(prices, n, idx + 1, bought),           // wait (stay not bought)
                -prices[idx] + recc(prices, n, idx + 1, !bought) // buy (go to bought)
            );
        }
        
        return dp[idx][bought];
    }

public:
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(prices.size(), vector<int>(2, -1));
        return recc(prices, prices.size(), 0, false);
    }
};

// Solution 2:
// bottom-up DP with space optimization.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev1(2, 0);
        vector<int> prev2(2, 0);
        vector<int> curr(2, 0);

        for(int i = n-1; i >= 0; --i){
            curr[0] = max(prices[i] + prev2[1], 0 + prev1[0]);
            curr[1] = max(-prices[i] + prev1[0], 0 + prev1[1]);

            prev2 = prev1;
            prev1 = curr;
        }

        return curr[1];
    }
};