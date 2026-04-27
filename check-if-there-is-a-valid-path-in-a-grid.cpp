class Solution {
private:
vector<vector<bool>> visited_;
vector<vector<int>> dir_;
int m_, n_;

bool isDirectionAllowed(int dir, int street_type, int next_street_type){
    return ((dir == 0 && (street_type == 1 || street_type == 3 || street_type == 5) && (next_street_type == 1 || next_street_type == 4 || next_street_type == 6)) || 
        (dir == 1 && (street_type == 2 || street_type == 5 || street_type == 6) && (next_street_type == 2 || next_street_type == 3 || next_street_type == 4)) || 
        (dir == 2 && (street_type == 1 || street_type == 4 || street_type == 6) && (next_street_type == 1 || next_street_type == 3 || next_street_type == 5)) ||
        (dir == 3 && (street_type == 2 || street_type == 3 || street_type == 4) && (next_street_type == 2 || next_street_type == 5 || next_street_type == 6)));
}

bool dfs(int x, int y, const vector<vector<int>>& grid_){
    if(x == m_ - 1 && y == n_ - 1){
        return true;
    }

    visited_[x][y] = 1;
    int street_type = grid_[x][y];
    for(int i = 0; i < 4; ++i){
        int new_x = x + dir_[i][0];
        int new_y = y + dir_[i][1];

        if((new_x >= 0 && new_x < m_ && new_y >= 0 && new_y < n_) &&
            isDirectionAllowed(i, street_type, grid_[new_x][new_y]) &&
            !visited_[new_x][new_y] && dfs(new_x, new_y, grid_)){
                return true;
        }
    }

    return false;
}

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        m_ = grid.size(), n_ = grid[0].size();
        visited_ = vector<vector<bool>>(m_, vector<bool>(n_, 0));
        dir_ = {
            {0, -1},
            {-1, 0},
            {0, 1},
            {1, 0},
        };

        return dfs(0, 0, grid);
    }
};