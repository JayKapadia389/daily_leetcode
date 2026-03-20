// Solution 1:
// O(m * n* k^2 * logk)
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int m_shrunk = (m - k + 1), n_shrunk = (n - k + 1);
        vector<vector<int>> ans(m_shrunk, vector<int>(n_shrunk));

        for(int i = 0; i < m_shrunk; ++i){
            for(int j = 0; j < n_shrunk; ++j){
                vector<int> temp;

                for(int p = 0; p < k; ++p){
                    for(int q = 0; q < k; ++q){
                        temp.push_back(grid[i+p][j+q]);
                    }
                }

                sort(temp.begin(), temp.end());

                int mn = INT_MAX;

                for(int l = 0; l < (k*k - 1); ++l){
                    if(temp[l] != temp[l+1]){
                        mn = min(mn, abs(temp[l] - temp[l+1]));
                    }
                }

                ans[i][j] = (mn == INT_MAX)? 0 : mn;
            }
        }

        return ans;
    }
};

// Solution 2 (not mine):
// O(m * n * k^2)
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> ans(n - k + 1, vector<int>(m - k + 1));
        for (int i = 0; i <= n - k; i++) {
            map<int, int> mp;
            for (int r = i; r < i + k; r++) {
                for (int c = 0; c < k; c++) {
                    mp[grid[r][c]]++;
                }
            }
            for (int c = 0; c <= m - k; c++) {
                if (mp.size() > 1) {
                    int mini = 1e9;
                    auto it = mp.begin();
                    int prev = it->first;
                    for (++it; it != mp.end(); it++) {
                        mini = min(mini, abs(it->first - prev));
                        prev = it->first;
                    }
                    ans[i][c] = mini;
                } else {
                    ans[i][c] = 0;
                }

                if (c < m - k) {
                    for (int r = i; r < i + k; r++) {
                        mp[grid[r][c]]--;
                        if (mp[grid[r][c]] == 0)
                            mp.erase(grid[r][c]);
                        mp[grid[r][c + k]]++;
                    }
                }
            }
        }
        return ans;
    }
};