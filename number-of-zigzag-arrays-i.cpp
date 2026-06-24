// O(mn)
// DP + prefix sum optimization
int MOD = 1e9 + 7;

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<vector<int>> dp1(2, vector<int>(m));
        vector<vector<int>> dp2(2, vector<int>(m));

        for(int k = 0; k < m; ++k){
            dp2[0][k] = m - k - 1; 
            dp2[1][k] = k;
        }

        for(int i = 0; i < n - 2; ++i){
            long long prefix_sum = 0;
            for(int j = 0; j < m; ++j){
                dp1[1][j] = prefix_sum;
                prefix_sum = (prefix_sum + dp2[0][j]) % MOD;
            }

            prefix_sum = 0;
            for(int j = m - 1; j >= 0; --j){
                dp1[0][j] = prefix_sum;
                prefix_sum = (prefix_sum + dp2[1][j]) % MOD;
            }

            dp2 = dp1;
        }

        long long ans = 0;
        for(int i = 0; i < m; ++i){
            ans = (ans + dp2[0][i]) % MOD;
            ans = (ans + dp2[1][i]) % MOD;
        }

        return ans;
    }
};