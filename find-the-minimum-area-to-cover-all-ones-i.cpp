class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int lm = INT_MAX , rm = INT_MIN , tm = INT_MAX , bm = INT_MIN , m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    lm = min(lm , j);
                    rm = max(rm , j);
                    tm = min(tm , i);
                    bm = max(bm , i);
                }
            }
        }

        return (rm - lm + 1)*(bm - tm + 1);
    }
};