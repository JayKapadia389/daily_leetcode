class Solution {
    using PII = pair<int, int>;

private:
void dijkstra(vector<int>& cost, const vector<vector<pair<int, int>>>& adj){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0,0});

    while(!q.empty()){
        PII p = q.top();
        q.pop();
        int base_dis = p.first;
        int x = p.second;

        for(auto [y, edge_cost] : adj[x]){
            if((base_dis + edge_cost) < cost[y]){
                cost[y] = base_dis + edge_cost;
                q.push({base_dis + edge_cost, y});
            }
        }
    }
}

public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<PII>> adj(n);

        for(auto edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        vector<int> cost(n, INT_MAX);
        cost[0] = 0;
        dijkstra(cost, adj);

        return (cost[n-1] == INT_MAX) ? -1 : cost[n-1];
    }
};