class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size(), n = boxGrid[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(boxGrid[i][j] == '*'){
                    ans[j][m - i - 1] = '*';
                }
            }
        }

        for(int i = 0; i < m; ++i){
            int stone_cnt = 0;
            for(int l = 0, r = 0; l < n; ++r){
                if(r >= n || boxGrid[i][r] == '*'){
                    while(stone_cnt != 0){
                        ans[r - (stone_cnt--)][m - i - 1] = '#';
                    }
                    l = r + 1;
                }
                else{
                    if(boxGrid[i][r] == '#'){
                        ++stone_cnt;
                    }
                }
            }
        }

        return ans;
    }
};