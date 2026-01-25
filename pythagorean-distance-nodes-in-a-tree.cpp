class Solution {
private:
bool isPythagorian(vector<int>& item){
    long long a = item[0];
    long long b = item[1];
    long long c = item[2];
    
    long long sq_a = a * a;
    long long sq_b = b * b;
    long long sq_c = c * c;

    return ((sq_a + sq_b == sq_c) || (sq_a + sq_c == sq_b) || (sq_b + sq_c == sq_a));
}

void bfs(const vector<vector<int>>& adj, int x, vector<vector<int>>& table, int i, int n){
    vector<bool> visited(n,0);
    queue<int> q;
    q.push(x);
    visited[x] = 1;
    int len, dis = 0;

    while(!q.empty()){
        len = q.size();

        for(int j = 0; j < len; ++j){
            int curr = q.front();
            q.pop();

            table[curr][i] = dis;

            for(auto nei : adj[curr]){
                if(!visited[nei]){
                    visited[nei] = 1;
                    q.push(nei);
                }
            }
        }
        
        ++dis;
    }
}
    
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> table(n, vector<int>(3));
        vector<vector<int>> adj(n);

        // make adj list
        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        bfs(adj, x, table, 0, n);
        bfs(adj, y, table, 1, n);
        bfs(adj, z, table, 2, n);

        int cnt = 0;
        for(auto& item :table){
            if(isPythagorian(item)){
                ++cnt;
            }
        }   
        return cnt;
    }
};