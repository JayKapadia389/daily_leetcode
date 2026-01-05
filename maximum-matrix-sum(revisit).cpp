class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int n = matrix.size(), minimum = INT_MAX;
        bool minus = 0;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int curr = matrix[i][j];
                ans += abs(curr);
                if(curr < 0) minus = !minus;
                minimum = min(minimum, abs(curr));
            }
        }

        if(minus && minimum != 0){
            ans -= (2*minimum);
        }

        return ans;
    }
};