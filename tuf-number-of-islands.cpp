class Solution{
private:
    vector<vector<bool>> visited_;
    vector<vector<int>> dir_;
    int n_,m_;

    void dfs(int i,int j, vector<vector<char>> &grid){
        visited_[i][j] = 1;

        for(int k = 0; k < 4; ++k){
            int x = i+dir_[k][0];
            int y = j+dir_[k][1];

            if((x >= 0 && x < n_ && y >= 0 && y < m_) && 
                grid[x][y] &&
                !visited_[x][y]){
                    dfs(x,y,grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid){
        
        n_ = grid.size();
        m_ = grid[0].size();
        int cnt = 0;
        visited_ = vector<vector<bool>>(n_, vector<bool>(m_,0));
        dir_ = {
            {-1,0},
            {0,1},
            {1,0},
            {0,-1},
        };

        for(int i = 0; i<n_; ++i){
            for(int j = 0; j<m_; ++j){
                if(grid[i][j] && !visited_[i][j]){
                    dfs(i,j,grid);
                    ++cnt;
                }
            }
        }
        return cnt; 
    }
};
