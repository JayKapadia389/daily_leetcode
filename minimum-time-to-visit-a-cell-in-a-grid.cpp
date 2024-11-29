class Solution {
public:

    vector<vector<int>> dir = {
        {-1 , 0} ,
        {0 , 1} ,
        {1 , 0} ,
        {0 , -1} ,
    };

    int m_, n_;
    vector<vector<bool>> visited_;

    bool valid(int newX, int newY) {
        if (newX < 0 || newX >= m_ || newY < 0 || newY >= n_) {
            return 0;
        }
        else if (visited_[newX][newY]) {
            return 0;
        }
        return 1;
    }

    int minimumTime(vector<vector<int>>& grid) {

        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }

        int newX, newY;

        m_ = grid.size();
        n_ = grid[0].size();

        vector<vector<bool>> visited(m_, vector<bool>(n_, 0));
        visited_ = visited;

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;

        pq.push({ 0 , 0 , 0 });

        while (!pq.empty()) {

            vector<int> curr = pq.top();
            pq.pop();

            if (curr[1] == m_ - 1 && curr[2] == n_ - 1) {
                return curr[0];
            }

            if (visited[curr[1]][curr[2]]) {
                continue;
            }
            visited[curr[1]][curr[2]] = 1;

            for (int i = 0; i < 4; i++) {
                newX = curr[1] + dir[i][0];
                newY = curr[2] + dir[i][1];
                if (valid(newX, newY)) {

                    int waitTime =
                        ((grid[newX][newY] - curr[0]) % 2 == 0) ? 1 : 0;
                    int nextTime = max(grid[newX][newY] + waitTime, curr[0] + 1);
                    pq.push({ nextTime, newX, newY });

                }
            }

        }

        return -1;

    }
};