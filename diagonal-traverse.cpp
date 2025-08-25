class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        vector<int> ans;
        bool even = 1;

        for(int i = 0; i <= ((m-1)+(n-1)); ++i){

            if(even){
                for(int j = i; j >= 0; --j){
                    if(j < m && j >= 0 && (i-j) < n && (i-j) >= 0 ){
                        ans.push_back(mat[j][i - j]);
                    }
                }
            }
            else{
                for(int j = 0; j <= i; ++j){
                    if(j < m && j >= 0 && (i-j) < n && (i-j) >= 0 ){
                        ans.push_back(mat[j][i - j]);
                    }
                }
            }

            even = !even;
        }

        return ans;
        
    }
};