int INF = INT_MAX;

class Solution {
private:
int manhattan_dist(pair<int, int>& a, pair<int, int>& b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(), total_dist = 0;
        vector<pair<int, int>> map(n);
        vector<bool> selected(n, 0);
        vector<pair<int, int>> dist(n, {INF, -1});

        for(int i = 0; i < points.size(); ++i) {
            map[i].first = points[i][0];
            map[i].second = points[i][1];
        }

        selected[0] = true;

        for(int i = 0; i < n; ++i) {
            int dist_from_0 = manhattan_dist(map[0], map[i]);
            dist[i] = {dist_from_0, 0};
        }

        for(int i = 1; i < n; ++i) {
            int closest_node;
            int closest_node_dist = INF;

            for(int j = 0; j < n; ++j) {
                if(!selected[j] && (dist[j].first < closest_node_dist)) {
                    closest_node = j;
                    closest_node_dist = dist[j].first;
                }
            }

            selected[closest_node] = true;
            total_dist += closest_node_dist;

            for(int j = 0; j < n; ++j) {
                if(!selected[j] && manhattan_dist(map[closest_node], map[j]) < dist[j].first) {
                    dist[j].first = manhattan_dist(map[closest_node], map[j]);
                    dist[j].second = closest_node;
                }
            }
        }

        return total_dist;
    }
};