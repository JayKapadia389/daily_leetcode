int MOD = 1e9 + 7;
int m = 200;

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp1(m+1, vector<int>(m+1, 0));

        dp1[0][0] = 1;
        dp1[0][nums[0]] = 1;
        dp1[nums[0]][0] = 1;

        for(int c = 1; c <= n - 1; ++c) {
            vector<vector<int>> dp2(m + 1, vector<int>(m + 1));

            for(int i = 0; i <= m; ++i) {
                int g1 = gcd(i, nums[c]);

                for(int j = 0; j <= m; ++j) {
                    int val = dp1[i][j];
                    if(val == 0) continue;

                    int g2 = gcd(j, nums[c]);
                    dp2[i][j] =  (dp2[i][j] + val) % MOD;
                    dp2[g1][j] = (dp2[g1][j] + val) % MOD;
                    dp2[i][g2] = (dp2[i][g2] + val) % MOD;
                }
            }
            dp1.swap(dp2);
        }

        int ans = 0;
        for(int i = 1; i <= m; ++i) {
            ans = (ans + dp1[i][i]) % MOD;
        }

        return ans;
    }
};