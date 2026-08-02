#define PII pair<int, int>

// Solution 1:
// O(n^2) 3D DP
class Solution {
private:
PII recc(int l, int r, bool turn, vector<vector<vector<PII>>>& dp,vector<int>& piles) {
    if(l > r){
        return {0, 0};
    }

    if(dp[l][r][turn].first != -1){
        return dp[l][r][turn];
    }

    PII left = recc(l + 1, r, !turn, dp, piles);
    PII right = recc(l, r - 1, !turn, dp , piles);
    
    if(!turn) { // Alice
        left.first += piles[l];
        right.first += piles[r];
        if((left.first - left.second) >= (right.first - right.second)){
            return dp[l][r][turn] = left;
        }
        else{
            return dp[l][r][turn] = right;
        }
    }
    else{ // Bob
        left.second += piles[l];
        right.second += piles[r];
        if((left.second - left.first) >= (right.second - right.first)){
            return dp[l][r][turn] = left;
        }
        else{
            return dp[l][r][turn] = right;
        }
    }
}

public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<PII>>> dp(n, vector<vector<PII>>(n, vector<PII>(2, {-1, -1})));

        PII p = recc(0, n - 1, 0, dp, piles);

        return p.first > p.second; 
    }
};