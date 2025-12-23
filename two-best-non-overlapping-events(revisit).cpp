class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size(), ans = 0;
        vector<int> suffix(n);

        sort(events.begin(), events.end());

        for(int i = n - 1; i >= 0; --i){
            if(i == n-1)
                suffix[i] = events[i][2];
            else
                suffix[i] = max(suffix[i+1], events[i][2]);
        }

        for(int i = 0; i < n; ++i){
            int sum = events[i][2];
            auto it = std::upper_bound(events.begin(), events.end(), vector<int>{events[i][1], INT_MAX, INT_MAX});

            if(it != events.end()){
                sum += suffix[distance(events.begin(), it)];
            }

            ans = max(ans, sum);
        }

        return ans;
    }
};