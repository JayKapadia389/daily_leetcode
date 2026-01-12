class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int mx_rect = 0, m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> matrix_num(m, vector<int>(n));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                matrix_num[i][j] =  matrix[i][j] - '0';
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = n-2; j >= 0; --j){
                if(matrix_num[i][j] == 1) matrix_num[i][j] += matrix_num[i][j+1];
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int k = 0, len = matrix_num[i][j];
                while((i+k) < m && matrix_num[i+k][j] != 0){
                    len = min(matrix_num[i+k][j], len);
                    mx_rect = max(mx_rect, len*(k+1));
                    ++k;
                }
            }
        }
        return mx_rect;
    }
};