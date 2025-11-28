class Solution {
private:
int recc(int curr, int parent, int& ans, vector<vector<int>>& adj, vector<int>& values, int& k ){
    int sum = values[curr] % k;

    for(auto n : adj[curr]){
        if(n != parent){
            sum = (sum + recc(n, curr, ans, adj, values, k))%k;
        }
    }

    if(sum == 0){
        ++ans;
    }

    return sum;
}

public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int ans = 0;

        recc(0, -1, ans, adj, values, k);

        return ans;
    }
};