class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // bottom-left triangle
        for(int i = 0; i < n; ++i){
            int x = i , y = 0;
            vector<int> temp;

            for(; x < n; ++x, ++y){
                temp.push_back(grid[x][y]);
            }

            sort(temp.begin() , temp.end() , greater<int>());

            x = i , y = 0;
            for(; x < n; ++x, ++y){
                grid[x][y] = temp[y];
            }
        }

        // top-right triangle
        for(int j = 1; j < n; ++j){
            int x = 0 , y = j;
            vector<int> temp;

            for(; y < n; ++x, ++y){
                temp.push_back(grid[x][y]);
            }

            sort(temp.begin() , temp.end());

            x = 0 , y = j;
            for(; y < n; ++x, ++y){
                grid[x][y] = temp[x];
            }
        }

        return grid;
    }
};