class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), layers = min(m, n) / 2;

        for(int l = 0; l < layers; ++l){
            int m_ = m - 2 * l, n_ = n - 2 * l;
            int size = 2*(m_ + n_) - 4;
            vector<int> temp(size), temp2(size);

            int j = 0;
            for(int i = 0; i < n_ - 1; ++i){
                temp[j++] = grid[l][l+i];
            }
            for(int i = 0; i < m_ - 1; ++i){
                temp[j++] = grid[l+i][n - l - 1];
            }
            for(int i = 0; i < n_ - 1; ++i){
                temp[j++] = grid[m - l - 1][n - l - 1 - i];
            }
            for(int i = 0; i < m_ - 1; ++i){
                temp[j++] = grid[m - l - i - 1][l];
            }

            int k_ = k % size;
            for(int i = 0; i < size; ++i){
                temp2[(i - k_ + size) % size] = temp[i];
            }

            j = 0;
            for(int i = 0; i < n_ - 1; ++i){
                grid[l][l+i] = temp2[j++];
            }
            for(int i = 0; i < m_ - 1; ++i){
                grid[l+i][n - l - 1] = temp2[j++];
            }
            for(int i = 0; i < n_ - 1; ++i){
                grid[m - l - 1][n - l - 1 - i] = temp2[j++];
            }
            for(int i = 0; i < m_ - 1; ++i){
                grid[m - l - i - 1][l] = temp2[j++];
            }
        }

        return grid;
    }
};