class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {

        for(int i = 0; i < (k/2); ++i){
            for(int j = 0; j < k; ++j){
                int temp = grid[x+i][y+j];
                grid[x+i][y+j] = grid[x+(k-1)-i][y+j];
                grid[x+(k-1)-i][y+j] = temp;
            }
        }

        return grid;
    }
};