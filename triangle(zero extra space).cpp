class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(); // Number of rows

        for(int i = n-2; i >= 0; --i){
            for(int j = 0; j <= i; ++j){
                // We are using the last row for processing
                triangle[n-1][j] = triangle[i][j] + min(triangle[n-1][j], triangle[n-1][j+1]);
            }
        }

        return triangle[n-1][0];
    }
};