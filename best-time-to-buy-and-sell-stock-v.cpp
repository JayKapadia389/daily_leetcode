class Solution {
private: 
int n_;
vector<vector<vector<long long>>> dp_;
vector<int> prices_;
long long NEG_INF = LLONG_MIN / 4;

long long solve(int i, int d, int k){
    if(i == n_)
        return (d == 0) ? 0 : NEG_INF;

    if(dp_[i][d][k] != LLONG_MIN)
        return dp_[i][d][k];
    
    long long dontTake = solve(i+1, d, k);
    long long take = NEG_INF;

    if(k > 0){
        if(d == 0){
            take = max(solve(i+1, 1, k) - prices_[i], solve(i+1, 2, k) + prices_[i]);
        }
        else if(d == 1){
            take = solve(i+1, 0, k-1) + prices_[i];
        }
        else{
            take = solve(i+1, 0, k-1) - prices_[i];
        }
    }

    return (dp_[i][d][k] = max(take, dontTake));
}

public:
    long long maximumProfit(vector<int>& prices, int k) {
        n_ = prices.size();
        prices_ = prices;
        dp_ = vector<vector<vector<long long>>>(n_, vector<vector<long long>>(3, vector<long long>(k+1, LLONG_MIN)));

        return solve(0, 0, k);
    }
};