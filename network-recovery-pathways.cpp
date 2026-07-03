#define PII pair<int, int>
long long INF = LLONG_MAX;

class Solution {
private:
int n_;
long long k_;
vector<bool> online_;
vector<vector<PII>> adj_;

long long shortestPathToLastNode(int curr,int score, vector<long long>& costs) {
    if(costs[curr] != -1) return costs[curr];

    long long curr_cost = INF;
    for(auto nei : adj_[curr]) {
        int v = nei.first;
        int edge_cost = nei.second;

        if(online_[v] && edge_cost >= score) {
            long long sub_cost = shortestPathToLastNode(v, score, costs);

            if(sub_cost != INF) {
                curr_cost = min(curr_cost, sub_cost + edge_cost);
            }
        }
    }

    return costs[curr] = curr_cost;
}

bool scoreGreaterOrEqualToXExists(int score) {
    vector<long long> costs(n_, -1);
    costs[n_ - 1] = 0;
    return shortestPathToLastNode(0, score, costs) <= k_;
}

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n_ = online.size();
        k_ = k;
        online_ = online;
        int mx_score = -1;
        int l = 0, r = 1e9;
        vector<vector<PII>> adj(n_);

        // construct adjacency list
        for(const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int cost = edge[2];
            adj_[u].push_back({v, cost});
        }

        // binary search
        while(l <= r) {
            int mid = (l + r) / 2;

            if(scoreGreaterOrEqualToXExists(mid)) {
                mx_score = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }

        return mx_score;
    }
};