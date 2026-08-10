class Solution {
private:
bool recc(int n, vector<int>& dp){
    if(n == 0) return false;

    if(dp[n] != -1){
        return (dp[n] == 0) ? false : true;
    }

    for(int i = 1; i*i <= n; ++i) {
        if(!recc(n - i*i, dp)){
            dp[n] = 1;
            return true;
        }
    }

    dp[n] = 0;
    return false;
}

public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n + 1, -1);
        return recc(n, dp);
    }
};