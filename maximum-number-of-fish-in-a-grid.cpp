class Solution {
private:
    int calculateFishes(vector<vector<int>>& grid,
        vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;

        return grid[row][col] + calculateFishes(grid, visited, row, col + 1) +
            calculateFishes(grid, visited, row, col - 1) +
            calculateFishes(grid, visited, row + 1, col) +
            calculateFishes(grid, visited, row - 1, col);
    }

public:
    int findMaxFish(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int maxFishCount = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (grid[row][col] > 0 && !visited[row][col]) {
                    maxFishCount = max(
                        maxFishCount, calculateFishes(grid, visited, row, col));
                }
            }
        }

        return maxFishCount;
    }
};