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