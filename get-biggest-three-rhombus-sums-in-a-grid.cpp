class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> prefix_right(m, vector<int>(n));
        vector<vector<int>> prefix_left(m, vector<int>(n));

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                prefix_right[i][j] = grid[i][j] + ((i-1 >= 0 && j-1 >= 0)? prefix_right[i-1][j-1] : 0);
                prefix_left[i][j] = grid[i][j] + ((i-1 >= 0 && j+1 < n)? prefix_left[i-1][j+1] : 0);
            }
        }

        vector<int> ans(3, INT_MIN);
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                for(int size = 1; true; ++size){
                    int sum = 0;
                    if(size == 1){
                        sum = grid[i][j];
                    }
                    else{
                        int a = i + (size - 1);
                        int b = i + (size * 2 - 2);
                        int c = j - (size - 1);
                        int d = j + (size - 1);

                        if(!((a < m) && (b < m) && (c >= 0) && (d < n))) break;

                        sum += (prefix_right[a][d] - ((i-1 >= 0 && j-1 >= 0)? prefix_right[i-1][j-1] : 0));
                        sum += (prefix_left[a][c] - ((i-1 >= 0 && j+1 < n)? prefix_left[i-1][j+1] : 0));
                        sum -= grid[i][j];
                        sum += (prefix_right[b][j] - prefix_right[a][c]);
                        sum += (prefix_left[b][j] - prefix_left[a][d]);
                        sum -= grid[b][j];
                    }
                    
                    for(int k = 0; k < 3; ++k){
                        if(sum == ans[k]){
                            break;
                        }
                        else if(sum > ans[k]){
                            ans.insert(ans.begin() + k, sum);
                            ans.pop_back();
                            break;
                        }
                    }
                }
            }
        }

        while(ans.back() == INT_MIN) ans.pop_back();
        return ans;
    }
};