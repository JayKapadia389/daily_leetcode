class Solution {
private:
int len;

public:
    int recc(vector<pair<int,int>>& strs, int i, int m, int n, vector<vector<vector<int>>>& dp){
        if(i == len){
            return 0;
        }

        if(dp[i][m][n] != -1){
            return dp[i][m][n];
        }

        int not_taken = recc(strs, i+1, m, n, dp);

        int taken = 0;
        int new_m = m - strs[i].first;
        int new_n = n - strs[i].second;

        if(new_m >= 0 && new_n >= 0){
            taken = 1;
            taken += recc(strs, i+1, new_m, new_n, dp);
        }
        return (dp[i][m][n] = max(taken , not_taken));
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        len = strs.size();
        vector<vector<vector<int>>> dp(len+1, vector<vector<int>>(m+1, vector<int>(n+1, -1)));

        vector<pair<int,int>> strs_comp(len);

        for(int i = 0; i < len; ++i){
            int z = 0, o = 0;
            for(auto ch : strs[i]){
                if(ch == '0') ++z;
                else ++o;
            }
            strs_comp[i] = {z,o};
        }

        return recc(strs_comp, 0,m,n,dp);
    }
};