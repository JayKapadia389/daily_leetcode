#define p pair<int, pair<int, int>>

class Solution { 
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int logn = 32 - __builtin_clz(n);
        long long ans = 0;
        vector<vector<int>> stMax(n, vector<int>(logn));
        vector<vector<int>> stMin(n, vector<int>(logn));
        priority_queue<p, vector<p>> pq;

        for (int i = 0; i < n; i++) {
            stMax[i][0] = stMin[i][0] = nums[i];
        }

        for (int j = 1; j < logn; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                stMax[i][j] =
                    max(stMax[i][j - 1], stMax[i + (1 << (j - 1))][j - 1]);
                stMin[i][j] =
                    min(stMin[i][j - 1], stMin[i + (1 << (j - 1))][j - 1]);
            }
        }

        auto queryMax = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return max(stMax[l][j], stMax[r - (1 << j) + 1][j]);
        };

        auto queryMin = [&](int l, int r) {
            int j = 31 - __builtin_clz(r - l + 1);
            return min(stMin[l][j], stMin[r - (1 << j) + 1][j]);
        };

        // initialize priority queue
        for(int i = 0; i < n; ++i){
            int value = queryMax(i, n - 1) - queryMin(i, n - 1);
            pq.push({value, {i, n - 1}});
        }

        for(int i = 0; i < k; ++i){
            p pair = pq.top(); pq.pop();
            int value =  pair.first;
            int l = pair.second.first;
            int r = pair.second.second;

            ans += value;

            if(l < r){
                value = queryMax( l, r - 1) - queryMin( l, r - 1);
                pq.push({value, {l, r - 1}});
            }
        }

        return ans;
    }
};