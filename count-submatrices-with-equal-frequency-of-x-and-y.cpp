// TC: O(m*n)
// SC: O(min(m, n))
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        bool rowMajor = true;

        if(n > m){
            rowMajor = 0;
            swap(m, n);
        }

        vector<pair<int, int>> freq(n);

        for(int i = 0; i < m; ++i){
            pair<int, int> prefix = {0, 0};
            
            for(int j = 0; j < n; ++j){
                int rowIdx = rowMajor? i : j;
                int colIdx = rowMajor? j : i;

                if(grid[rowIdx][colIdx] == 'X'){
                    ++prefix.first;
                }
                else if(grid[rowIdx][colIdx] == 'Y'){
                    ++prefix.second;
                }

                freq[j].first += prefix.first;
                freq[j].second += prefix.second;

                if((freq[j].first != 0) && (freq[j].first == freq[j].second)){
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};