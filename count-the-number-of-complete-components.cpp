class Solution {
private:
vector<vector<int>> adj;
vector<bool> visited;
vector<int> comp_id_to_nodes_cnt;
vector<int> comp_id_to_edges_cnt_double;

void dfs(int node, const int& comp_id) {
    for(auto nei : adj[node]) {
        ++comp_id_to_edges_cnt_double[comp_id];
        if(!visited[nei]) {
            visited[nei] = 1;
            ++comp_id_to_nodes_cnt[comp_id];
            dfs(nei, comp_id);
        }
    }
}

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int comp_id = 0;
        int complete = 0;
        adj = vector<vector<int>>(n);
        visited = vector<bool>(n, 0);
        comp_id_to_nodes_cnt = vector<int>(n, 0);
        comp_id_to_edges_cnt_double = vector<int>(n, 0);

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i = 0; i < n; ++i) {
            if(!visited[i]){
                visited[i] = 1;
                comp_id_to_nodes_cnt[comp_id] = 1;
                dfs(i, comp_id);
                ++comp_id;
            }
        }

        for(int i = 0; i < comp_id; ++i) {
            int e = comp_id_to_edges_cnt_double[i]/2;
            int n = comp_id_to_nodes_cnt[i];
            if((n * (n - 1) / 2) == e){
                ++complete;
            }
        }

        return complete;
    }
};