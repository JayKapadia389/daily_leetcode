class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> rows, cols;
        int ans = 0;

        for(auto& b : buildings){
            rows[b[0]].insert(b[1]);
            cols[b[1]].insert(b[0]);
        }

        for(auto& b : buildings){
            int x = b[0], y = b[1];
            // auto l = std::lower_bound(rows[x].begin(), rows[y].end(), y);
            // auto r = std::upper_bound(rows[x].begin(), rows[y].end(), y);
            auto l = rows[x].lower_bound(y);
            auto r = rows[x].upper_bound(y);

            if(l != rows[x].begin() && r != rows[x].end()){
                // auto l = std::lower_bound(cols[y].begin(), cols[y].end(), x);
                // auto r = std::upper_bound(cols[y].begin(), cols[y].end(), x);
                auto l = cols[y].lower_bound(x);
                auto r = cols[y].upper_bound(x);

                if(l != cols[y].begin() && r != cols[y].end()){
                    ++ans;
                }
            }
        }

        return ans;
    }
};