class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> union_find(n);
        vector<bool> ans(m);

        union_find[0] = 0;
        for(int i = 1; i < n; ++i) {
            if((nums[i] - nums[i - 1]) <= maxDiff) {
                union_find[i] = union_find[i - 1];
            }
            else {
                union_find[i] = i;
            }
        }

        for(int i = 0; i < m; ++i) {
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] = union_find[u] == union_find[v];
        }

        return ans;
    }
};