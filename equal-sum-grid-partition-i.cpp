class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> col_prefix(n);
        vector<long long> row_prefix(m);
        long long total = 0;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                total += grid[i][j];
            }
            row_prefix[i] = total;
        }

        total = 0;
        for(int j = 0; j < n; ++j){
            for(int i = 0; i < m; ++i){
                total += grid[i][j];
            }
            col_prefix[j] = total;
        }

        for(int i = 0; i < m-1; ++i){
            if(row_prefix[i] == total - row_prefix[i]){
                return true;
            }
        }

        for(int j = 0; j < n - 1; ++j){
            if(col_prefix[j] == total - col_prefix[j]){
                return true;
            }
        }

        return false;
    }
};