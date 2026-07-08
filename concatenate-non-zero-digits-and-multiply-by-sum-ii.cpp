#define LL long long

int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length(), n = queries.size();
        vector<int> ten_power(m + 1);
        vector<int> pre_x(m);
        vector<int> pre_sum(m);
        vector<int> pre_non_zeros(m);
        vector<int> ans(n);

        ten_power[0] = 1; 
        for(int i = 1; i <= m; ++i) {
            long long pro = ten_power[i - 1];
            pro *= 10;
            ten_power[i] = pro % MOD;
        }

        pre_x[0] = s[0] - '0';
        pre_sum[0] = s[0] - '0';
        pre_non_zeros[0] = ((s[0] - '0') == 0) ? 0 : 1;
        for(int i = 1; i < m; ++i) {
            int curr = s[i] - '0';

            pre_x[i] = pre_x[i - 1];
            pre_sum[i] = (pre_sum[i - 1] + (LL) curr) % MOD;
            pre_non_zeros[i] = pre_non_zeros[i - 1]; 

            if (curr != 0){
                pre_x[i] = (((pre_x[i] * (LL) 10) % MOD) + curr) % MOD;
                ++pre_non_zeros[i]; 
            }
        }

        for(int i = 0; i < n; ++i) {
            int l = queries[i][0], r = queries[i][1];

            int pre_sum_l = (l == 0) ? 0 : pre_sum[l - 1];
            int pre_sum_r = pre_sum[r];
            int sum = pre_sum_r - pre_sum_l;

            LL pre_x_l = (l == 0) ? 0 : pre_x[l - 1];
            int pre_x_r = pre_x[r];
            int n_z_l = (l == 0) ? 0 : pre_non_zeros[l - 1];
            int n_z_r = pre_non_zeros[r];
            int x = (pre_x_r - ((pre_x_l * ten_power[n_z_r - n_z_l]) % MOD) + MOD) % MOD;

            ans[i] = ((LL) x * sum) % MOD;
        }

        return ans;
    }
};