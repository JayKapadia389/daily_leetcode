class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        unordered_set<int> rows;
        unordered_set<int> cols;

        int m = matrix.size() , n = matrix[0].size();

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!matrix[i][j]){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        // rows
        for(auto row : rows){
            for(int j = 0; j < n; ++j){
                matrix[row][j] = 0;
            }
        }

        // cols
        for(auto col : cols){
            for(int i = 0; i < m; ++i){
                matrix[i][col] = 0;
            }
        }

        return;
    }
};