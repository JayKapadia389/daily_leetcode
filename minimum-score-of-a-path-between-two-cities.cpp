#define PII pair<int, int>

class Solution {
private:
void dfs(int a, const int& n, const vector<vector<PII>>& adj, int& mn, vector<bool>& visited) {
    for(const auto& road : adj[a]) {
        int b = road.first;
        int dis = road.second;

        mn = min(mn, dis);

        if(!visited[b]){
            visited[b] = 1;
            dfs(b, n, adj, mn, visited);
        }
    }
}

public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<PII>> adj(n + 1);
        vector<bool> visited(n + 1, 0);
        int mn = INT_MAX;

        for(const auto& road : roads) {
            int a = road[0];
            int b = road[1];
            int dis = road[2];
            adj[a].push_back({b, dis});
            adj[b].push_back({a, dis});
        }

        visited[1] = 1;
        dfs(1, n, adj, mn, visited);
        return mn;
    }
};