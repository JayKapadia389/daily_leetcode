class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int special = 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> row_cnt(m, 0);

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j]){
                    row_cnt[i]++;
                }
            }
        }

        for(int j = 0; j < n; ++j){
            bool potentially_special_found = 0;
            for(int i = 0; i < m; ++i){
                if(mat[i][j]){
                    if(potentially_special_found){
                        --special;
                        break;
                    }

                    if(row_cnt[i] != 1){
                        break;
                    }

                    potentially_special_found = 1;
                    ++special;
                }
            }
        }

        return special;
    }
};