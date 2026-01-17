class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int square_dimension = 0;
        int n = bottomLeft.size();

        for(int i = 0; i < n; ++i){
            for(int j = i + 1; j < n; ++j){
                int x_overlap = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                int y_overlap = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                square_dimension = max(square_dimension, min(x_overlap, y_overlap));
            }
        }

        return pow(square_dimension, 2);
    }
};