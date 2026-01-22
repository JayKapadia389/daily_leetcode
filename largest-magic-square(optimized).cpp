class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> h_prefix(m, vector<int>(n));
        vector<vector<int>> v_prefix(m, vector<int>(n));
        vector<vector<int>> d1_prefix(m, vector<int>(n));
        vector<vector<int>> d2_prefix(m, vector<int>(n));

        // h_prefix
        for (int i = 0; i < m; ++i) {
            h_prefix[i][0] = grid[i][0];
            for (int j = 1; j < n; ++j) {
                h_prefix[i][j] = h_prefix[i][j - 1] + grid[i][j];
            }
        }

        // v_prefix
        for (int j = 0; j < n; ++j) {
            v_prefix[0][j] = grid[0][j];
            for (int i = 1; i < m; ++i) {
                v_prefix[i][j] = v_prefix[i - 1][j] + grid[i][j];
            }
        }

        // d1_prefix
        for(int i = m-1; i >= 0; --i){
            for(int j = 0; j < n; ++j){
                d1_prefix[i][j] = (i == m-1 || j == 0)? grid[i][j] : d1_prefix[i+1][j-1] + grid[i][j];
            }
        }

        // d2_prefix
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                d2_prefix[i][j] = (i == 0 || j == 0)? grid[i][j] : d2_prefix[i-1][j-1] + grid[i][j];
            }
        }

        for(int k = min(m, n) ;k >= 2; --k){
            for(int i = 0; (i+k) <= m; ++i){
                for(int j = 0; (j+k) <= n; ++j){
                    int sum = -1;
                    bool fail = 0;

                    //check horizontal
                    for(int p = 0; p < k; ++p){
                        int sum_curr = h_prefix[i+p][j+k-1] - ((j == 0)? 0 : h_prefix[i+p][j-1]);
                        if(sum == -1){
                            sum = sum_curr;
                        }
                        else{
                            if(sum_curr != sum){
                                fail = 1;
                                break;
                            }
                        }
                    }
                    if(fail) continue;

                    // verticle
                    for(int p = 0; p < k; ++p){
                        int sum_curr = v_prefix[i+k-1][j+p] - ((i == 0)? 0 : v_prefix[i-1][j+p]);
                        if(sum_curr != sum){
                            fail = 1;
                            break;
                        }
                    }
                    if(fail) continue;

                    // d1
                    int sum_curr = d1_prefix[i][j+k-1] - ((j == 0 || i+k == m)? 0 : d1_prefix[i+k][j-1]);
                    if(sum_curr != sum) fail = 1;
                    if(fail) continue;

                    // d2 
                    sum_curr = d2_prefix[i+k-1][j+k-1] - ((i == 0 || j == 0)? 0 : d2_prefix[i-1][j-1]);
                    if(sum_curr != sum) fail = 1;
                    if(fail) continue;

                    return k;
                }
            }
        }

        return 1;
    }
};