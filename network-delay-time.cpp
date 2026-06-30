#define PII pair<int, int>

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int INF = INT_MAX;
        int max_time = INT_MIN;
        vector<vector<PII>> adj(n + 1);
        vector<int> time(n + 1, INF);
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        
        for(auto egde : times){
            int u = egde[0];
            int v = egde[1]; 
            int w = egde[2]; 
            adj[u].push_back({v, w});
        }

        time[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            PII p = pq.top();
            pq.pop();

            int base_w = p.first;
            int u = p.second;

            for(PII nei : adj[u]){
                int v = nei.first;
                int w = nei.second;

                if(base_w + w < time[v]){
                    time[v] = base_w + w;
                    pq.push({base_w + w, v});
                }
            }
        }

        for(int i = 1; i <= n; ++i){
            max_time = max(max_time, time[i]);
        }

        return (max_time == INF) ? -1 : max_time;
    }
};