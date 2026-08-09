#define VI vector<int>
#define VVI vector<VI>
#define VVVI vector<VVI>

class Solution {
private:
int n;

int recc(int idx, int m, vector<int>& piles, VVI& dp) {
    if(idx == n){
        return 0;
    }

    if(dp[idx][m] != -1){
        return dp[idx][m];
    }

    int mx_diff = INT_MIN;
    int total = 0;

    for(int i = 1; i <= 2*m && i <= (n - idx); ++i) {
        total += piles[idx + i - 1];
        mx_diff = max(mx_diff, total - recc(idx + i, max(m, i), piles, dp));
    }

    return dp[idx][m] = mx_diff;
}

public:
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        int total = 0;
        VVI dp(n, VI(201, -1));

        int diff = recc(0, 1, piles, dp);

        for(auto pile : piles){
            total += pile;
        }

        return (diff + total) / 2;
    }
};