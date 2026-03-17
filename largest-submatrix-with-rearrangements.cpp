class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> cnt(n, 0);

        int mx = 0;
        for(int i = m - 1; i >= 0; --i){
            for(int j = 0; j < n; ++j){
                cnt[j] = (matrix[i][j] == 1)? cnt[j] + 1 : 0;
            }

            vector<int> temp = cnt;
            sort(temp.begin(), temp.end(), greater<>());

            for(int j = 0; j < n; ++j){
                mx = max(mx, temp[j]*(j+1));
            }
        }

        return mx;
    }
};