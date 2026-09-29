v=class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if(((m + n - 1) % 2) != 0) {
            return false;
        }

        if(grid[0][0] != '(' || grid[m - 1][n - 1] != ')') {
            return false;
        }

        vector<vector<set<int>>> dp(m, vector<set<int>>(n, set<int>()));

        dp[0][0].insert(1);

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                int delta = grid[i][j] == '(' ? 1 : -1;

                if(i != 0) {
                    for(auto diff : dp[i - 1][j]) {
                        if((diff + delta) >= 0){
                            dp[i][j].insert(diff + delta);
                        }
                    }
                }
                
                if(j != 0) {
                    for(auto diff : dp[i][j - 1]) {
                        if((diff + delta) >= 0){
                            dp[i][j].insert(diff + delta);
                        }
                    }
                }
            }
        }

        return dp[m - 1][n - 1].contains(0);
    }
}