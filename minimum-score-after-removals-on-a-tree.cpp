class Solution {
private:
    int dfs(int parent, int curr, vector<unordered_set<int>>& desc, vector<int>& Xor,vector<vector<int>>& adj){
        desc[curr].insert(curr);
        for(auto i : adj[curr]){
            if(i != parent){
                Xor[curr] ^= dfs(curr,i,desc,Xor,adj);
                desc[curr].insert(desc[i].begin(), desc[i].end());
            }
        }
        return Xor[curr];
    }

public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n,vector<int>());

        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<unordered_set<int>> desc(n);
        vector<int> Xor(nums);

        int total = dfs(-1,0,desc,Xor,adj);
        int ans = INT_MAX;
        int f,s,t;

        // combinations
        for(int i = 1; i < n-1 ; ++i){
            for(int j = i+1; j < n; ++j){
                // case-1 i->j
                if(desc[i].find(j) != desc[i].end()){
                    f = Xor[j];
                    s = Xor[i]^Xor[j];
                    t =total^Xor[i];
                }
                // case j->i
                else if(desc[j].find(i) != desc[j].end()){
                    f = Xor[i];
                    s = Xor[i]^Xor[j];
                    t = total^Xor[j];
                }
                // case : independant
                else{
                    f = Xor[i];
                    s = Xor[j];
                    t = total^(Xor[i]^Xor[j]);
                }
                ans = min(ans, (max({f,s,t}) - min({f,s,t})));
            }
        }
        return ans;
    }
};