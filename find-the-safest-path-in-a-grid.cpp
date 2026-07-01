#define PII pair<int, int>

class Solution {
private:
int n_;
vector<vector<int>> dir_;

void fillD(vector<vector<int>>& d, vector<vector<int>>& grid){
    queue<PII> q;

    for(int i = 0; i < n_; ++i){
        for(int j = 0; j < n_; ++j){
            if(grid[i][j] == 1){
                d[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while(!q.empty()) {
        PII curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;

        for(int i = 0; i < 4; ++i){
            int new_x = x + dir_[i][0];
            int new_y = y + dir_[i][1];

            if(new_x >= 0 && new_x < n_ && new_y >= 0 && new_y < n_ && d[new_x][new_y] == -1){
                d[new_x][new_y] = d[x][y] + 1;
                q.push({new_x, new_y});
            }
        }
    }
}

bool pathExists(const vector<vector<int>>& d, int v) {
    if(d[0][0] < v) return false;

    vector<vector<bool>> visited(n_, vector<bool>(n_, 0));
    queue<PII> q;
    q.push({0,0});
    visited[0][0] = 1;

    while(!q.empty()) {
        PII curr = q.front();
        int x = curr.first;
        int y = curr.second;
        q.pop();

        for(int i = 0; i < 4; ++i){
            int new_x = x + dir_[i][0];
            int new_y = y + dir_[i][1];

            if(new_x >= 0 && new_x < n_ && new_y >= 0 && new_y < n_ && d[new_x][new_y] >= v && visited[new_x][new_y] == 0){
                if(new_x == n_ - 1 && new_y == n_ - 1) return true;
                visited[new_x][new_y] = 1;
                q.push({new_x, new_y});
            }
        }
    }

    return false;
}

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n_ = grid.size();
        int l = 0, r = n_ - 1;
        int mx_safeness_factor = 0;
        vector<vector<int>> d(n_, vector<int>(n_, -1));
        dir_ = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};

        fillD(d, grid);

        while(l <= r) {
            int v = (l + r) / 2;

            if(pathExists(d, v)){
                mx_safeness_factor = v;
                l = v + 1;
            }
            else{
                r = v - 1;
            }
        }

        return mx_safeness_factor;
    }
};