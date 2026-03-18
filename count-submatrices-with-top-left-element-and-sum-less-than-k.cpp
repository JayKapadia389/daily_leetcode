// TC: m*n for both

// Solution 1:
// As changes are made to the input which is not a good practice, the space complexity is m*n. 
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;

        for(int i = 0; i < m; ++i){
            int prefix = 0;
            for(int j = 0; j < n; ++j){
                prefix += grid[i][j];
                grid[i][j] = prefix + ((i > 0)? grid[i-1][j] : 0);
                if(grid[i][j] <= k){
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};

// Solution 2:
// As we only require the row above we can can use a vector to store the previous row.
// Thus the space complexity becomes min(m, n). 
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        bool rowMajor = 1;
        int cnt = 0;

        if(m < n){
            rowMajor = 0;
            swap(m, n);
        }

        vector<int> prev(n, 0);

        for(int i = 0; i < m; ++i){
            int prefix = 0;
            for(int j = 0; j < n; ++j){
                prefix += rowMajor ? grid[i][j] : grid[j][i];
                prev[j] = prefix + prev[j];
                if(prev[j] <= k){
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};