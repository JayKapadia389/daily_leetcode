class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {

        int n = grid[0].size();

        if (n == 1)
            return 0;

        long long x = 0, y = 0;
        for (auto i : grid[0]) {
            y += i;
        }
        y -= grid[0][0];

        long long ans = max(x, y);

        for (int i = 1; i < n; i++) {
            y -= grid[0][i];
            x += grid[1][i - 1];

            ans = min(ans, max(x, y));
        }

        return ans;

    }
};