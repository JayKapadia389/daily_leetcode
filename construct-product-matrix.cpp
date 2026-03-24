int MOD = 12345;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefix_prod(m, vector<int>(n));

        long long product = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                prefix_prod[i][j] = product;
                product = (product * grid[i][j]) % MOD;
            }   
        }

        product = 1;
        for(int i = m-1 ; i >= 0; --i){
            for(int j = n-1; j >= 0; --j){
                int temp = grid[i][j];
                grid[i][j] = (prefix_prod[i][j] * product) % MOD;
                product = (product * temp) % MOD;
            }   
        }

        return grid;
    }
};