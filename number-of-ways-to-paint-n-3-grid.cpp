int mod = 1e9 + 7;

class Solution {
private:
static constexpr int lu[12][3] = {
    {0, 1, 0},
    {0, 1, 2},
    {0, 2, 0},
    {0, 2, 1},
    {1, 0, 2},
    {1, 0, 1},
    {1, 2, 0},
    {1, 2, 1},
    {2, 0, 1},
    {2, 0, 2},
    {2, 1, 0},
    {2, 1, 2}
};

bool compatible(int j, int k){
    return (lu[j][0] != lu[k][0] && lu[j][1] != lu[k][1] && lu[j][2] != lu[k][2]);
}

public:
    int numOfWays(int n) {
        int ans = 0;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(3, vector<vector<int>>(3, vector<int>(3, 0))));

        // Initialize for 0th row
        for(int i = 0; i < 12; ++i){
            dp[0][lu[i][0]][lu[i][1]][lu[i][2]] = 1;
        }

        for(int i = 1; i < n; ++i){
            for(int j = 0; j < 12; ++j){
                int val = dp[i-1][lu[j][0]][lu[j][1]][lu[j][2]];

                for(int k = 0; k < 12; ++k){
                    if(compatible(j, k)){
                        dp[i][lu[k][0]][lu[k][1]][lu[k][2]] = (dp[i][lu[k][0]][lu[k][1]][lu[k][2]] + val) % mod;
                    }
                }
            }
        }

        for(int i = 0; i < 12; ++i){
            ans = (ans + dp[n-1][lu[i][0]][lu[i][1]][lu[i][2]]) % mod;
        }

        return ans;
    }
};