class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat[0].size(), m = mat.size();
        vector<int> temp(n);

        for(int i = 0; i < m; ++i){
            if(i % 2 == 0){
                for(int j = 0; j < n; ++j){
                    temp[(j - k + 50*n) % n] = mat[i][j];
                }
            }
            else{
                for(int j = 0; j < n; ++j){
                    temp[(j + k) % n] = mat[i][j];
                }
            }

            if(temp != mat[i]){
                return false;
            }
        }

        return true;
    }
};