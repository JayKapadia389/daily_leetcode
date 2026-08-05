class Solution {
private:
void dfs(int curr, const vector<vector<int>>& adj, vector<int>& group_indegrees, vector<bool>& visited) {
    ++group_indegrees[curr];
    if(visited[curr]) return;

    visited[curr] = 1;

    for(auto nei : adj[curr]){
        dfs(nei, adj, group_indegrees, visited);
    }
}

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> total_indegrees(n, 0);
        vector<int> group_indegrees(n, 0);
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> visited(n, 0);
        vector<int> remaining;

        for(const auto& inv : invocations){
            int u = inv[0];
            int v = inv[1];
            adj[u].push_back(v);
            ++total_indegrees[v];
        }

        dfs(k, adj, group_indegrees, visited);
        --group_indegrees[k];

        for(int i = 0; i < n; ++i){
            if(visited[i]){
                if(group_indegrees[i] != total_indegrees[i]){
                    vector<int> v(n);
                    iota(v.begin(), v.end(), 0);
                    return v;
                }
            }
            else{
                remaining.push_back(i);
            }
        }

        return remaining;
    }
};