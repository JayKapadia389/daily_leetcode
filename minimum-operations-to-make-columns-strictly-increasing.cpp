class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {

        int acc = 0;
        int m = grid.size(), n = grid[0].size(), diff;

        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {

                if (grid[i][j] <= grid[i - 1][j]) {
                    diff = grid[i - 1][j] - grid[i][j] + 1;

                    acc += diff;

                    grid[i][j] += diff;
                }
            }
        }

        return acc;

    }
};