#define PII pair<int, int>
#define LL long long
int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<PII>> dp(n, vector<PII>(n));
        dp[n - 1][n - 1] = {0, 1};

        for(int i = n - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                if(i == n - 1 && j == n - 1) continue;
                if(board[i][j] == 'X') {
                    dp[i][j] = {0, 0};
                    continue;
                }

                int mx_sum = 0;
                LL freq = 0;

                if(i < n - 1){
                    mx_sum = max(mx_sum, dp[i + 1][j].first);
                }
                if(j < n - 1){
                    mx_sum = max(mx_sum, dp[i][j + 1].first);
                }
                if(i < n - 1 && j < n - 1){
                    mx_sum = max(mx_sum, dp[i + 1][j + 1].first);
                }

                if(i < n - 1 && dp[i + 1][j].first == mx_sum){
                    freq = (freq + dp[i + 1][j].second) % MOD;
                }
                if(j < n - 1 && dp[i][j + 1].first == mx_sum){
                    freq = (freq + dp[i][j + 1].second) % MOD;
                }
                if(i < n - 1 && j < n - 1 && dp[i + 1][j + 1].first == mx_sum){
                    freq = (freq + dp[i + 1][j + 1].second) % MOD;
                }

                dp[i][j] = {mx_sum, freq};

                if(board[i][j] != 'E' && freq != 0) {
                    dp[i][j].first += (board[i][j] - '0');
                }
            }      
        }

        vector<int> ans = {dp[0][0].first, dp[0][0].second};
        return ans; 
    }
};