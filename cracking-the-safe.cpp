class Solution {
private:
int k_;

void recc(string curr, unordered_map<string, int>& adj, string& ans) {
    if(adj.find(curr) == adj.end()) {
        adj[curr] = 0;
    }
    
    string next_base = curr.substr(1);
    while(adj[curr] != k_) {
        ++adj[curr];
        recc(next_base + to_string(adj[curr] - 1), adj, ans);
    }
    ans.push_back(curr.back());
}

public:
    string crackSafe(int n, int k) {
        string ans;
        ans.reserve(pow(k, n) + (n - 1));
        if(n == 1) {
            for(int i = 0; i < k; ++i){
                ans += to_string(i);
            }
            return ans;
        }
        
        unordered_map<string, int> adj;
        k_ = k;
        string starter(n - 1, '0');
        recc(starter, adj, ans);
        
        ans += starter.substr(0, n - 2);
        return ans;
    }
};

// k^n + (n - 1)