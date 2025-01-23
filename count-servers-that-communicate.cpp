class Solution {
public:
    int countServers(vector<vector<int>>& grid) {

        int m = grid.size(), n = grid[0].size();

        vector<pair<int, int>> servers;
        vector<int> rowFreq(m, 0);
        vector<int> colFreq(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    servers.push_back({ i,j });
                    ++rowFreq[i];
                    ++colFreq[j];
                }
            }
        }

        int ans = 0;

        for (auto p : servers) {
            if (rowFreq[p.first] > 1 || colFreq[p.second] > 1)
                ++ans;
        }

        return ans;

    }
};