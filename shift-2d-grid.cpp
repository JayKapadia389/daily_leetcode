class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j) {
                int target_i = (i + ((j + k) / n)) % m;
                int target_j = (j + k) % n;
                ans[target_i][target_j] = grid[i][j];
            }
        }

        return ans;
    }
};

// In-place:
//
// class Solution {
// public:
//     vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
//         int m = grid.size(), n = grid[0].size();
//         int size = m * n;

//         k = k % size;
//         if(k == 0) return grid;

//         auto reverse = [&](int i, int j) {
//             while(i < j){
//                 swap(grid[i / n][i % n], grid[j / n][j % n]);
//                 ++i;
//                 --j;
//             }
//         };

//         reverse(0, size - 1);
//         reverse(0, k - 1);
//         reverse(k, size - 1);

//         return grid;
//     }
// };