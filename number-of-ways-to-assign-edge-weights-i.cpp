int MOD = 1e9 + 7;

class Solution {
private:
void find_max_depth(vector<vector<int>>& adj, int& max_depth, int curr, int curr_depth, vector<int>& visited) {
    max_depth = max(curr_depth, max_depth);

    for(auto nei : adj[curr]){
        if(!visited[nei]){
            visited[nei] = true;
            find_max_depth(adj, max_depth, nei, curr_depth + 1, visited);
        }
    }
}

int power(int exp) {
    if(exp == 0) return 1;

    int multiplier = 1;
    if(exp % 2 != 0){
        --exp;
        multiplier = 2;
    }

    long long ans = power(exp / 2);
    ans = (ans * ans) % MOD;
    ans = (ans * multiplier) % MOD;
    return ans; 
}

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        vector<int> visited(n + 1, 0);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int max_depth = 0;
        visited[1] = true;
        find_max_depth(adj, max_depth, 1, 0, visited);

        return power(max_depth - 1);
    }
};