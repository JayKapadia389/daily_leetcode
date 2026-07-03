#define PII pair<int, int>
#define PIP pair<int, PII>
int INF_ = INT_MAX;

class Solution {
private:
int m_, n_;
vector<vector<int>> dir_ = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValidCell(int new_x, int new_y) {
    return new_x >= 0 && new_x < m_ && new_y >= 0 && new_y < n_;
}

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m_ = grid.size(), n_ = grid[0].size();
        int mn_cost;
        vector<vector<int>> costs(m_, vector<int>(n_, INF_));
        priority_queue<PIP, vector<PIP>, greater<PIP>> pq;
        costs[0][0] = grid[0][0];
        pq.push({costs[0][0], {0, 0}});

        while(!pq.empty()) {
            PIP cost_cell = pq.top();
            int cost = cost_cell.first;
            PII cell = cost_cell.second;
            int x = cell.first;
            int y = cell.second;
            pq.pop();

            for(const auto& d : dir_){
                int new_x = x + d[0];
                int new_y = y + d[1];

                if(isValidCell(new_x, new_y)){ 
                    if(costs[new_x][new_y] > (costs[x][y] + grid[new_x][new_y])){
                        costs[new_x][new_y] = costs[x][y] + grid[new_x][new_y];
                        pq.push({costs[new_x][new_y], {new_x, new_y}});
                    }
                }
            }
        }

        mn_cost = costs[m_ - 1][n_ - 1];
        return health > mn_cost;
    }
};