class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> points;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                points.push_back({i, j});
            }
        }
        sort(points.begin(), points.end(),
             [&](pair<int, int>& a, pair<int, int>& b) -> bool {
                 return grid[a.first][a.second] < grid[b.first][b.second];
             });

        for (int level = 0; level <= k; ++level) {
            // from below layer
            int mn = INT_MAX;
            for (int i = 0, j = 0; i < points.size(); ++i) {
                mn = min(mn, costs[points[i].first][points[i].second]);

                if (i + 1 == points.size() ||
                    grid[points[i].first][points[i].second] !=
                        grid[points[i + 1].first][points[i + 1].second]) {
                    for(int l = j; l <= i; ++l){
                        costs[points[l].first][points[l].second] = mn;
                    }
                    j = i + 1;
                }
            }

            // same layer
            for (int i = m - 1; i >= 0; --i) {
                for (int j = n - 1; j >= 0; --j) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        continue;
                    }
                    if (i != m - 1) {
                        costs[i][j] =
                            min(costs[i][j],
                                costs[i + 1][j] + grid[i + 1][j]);
                    }
                    if (j != n - 1) {
                        costs[i][j] =
                            min(costs[i][j],
                                costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }

        }

        return costs[0][0];
    }
};