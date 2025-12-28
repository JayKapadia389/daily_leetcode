class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size(), j = 0;

        for(int i = m-1; i >= 0; --i){
            for(; j < n; ++j){
                if(grid[i][j] < 0){
                    ans += (n - j);
                    break;
                }
            }
        }

        return ans;
    }
};