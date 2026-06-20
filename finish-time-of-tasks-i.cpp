class Solution {
private:
long long getFinishTime(int curr_task, const vector<int>& baseTime, const vector<vector<int>>& adj) {
    if(adj[curr_task].empty()){
        return baseTime[curr_task];
    }
    
    long long lt = LLONG_MIN, et = LLONG_MAX;
    
    for(auto child : adj[curr_task]){
        long long time = getFinishTime(child, baseTime, adj);
        et = min(et, time);
        lt = max(lt, time);
    }

    return 2*lt - et + baseTime[curr_task];
}
    
public:
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        
        return getFinishTime(0, baseTime, adj);
    }
};