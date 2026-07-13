#define PII pair<int, int>

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<PII> value_org_idx;
        vector<int> org_to_rel(n);
        int m = queries.size();
        vector<int> max_jump(n);

        for(int i = 0; i < n; ++i) {
            value_org_idx.push_back({nums[i], i});
        }

        sort(value_org_idx.begin(), value_org_idx.end());

        for(int i = 0; i < n; ++i) {
            org_to_rel[value_org_idx[i].second] = i;
        }

        for(int i = 0, j = 0; i < n && j < n;) {
            if((j == n - 1) || (value_org_idx[j + 1].first - value_org_idx[i].first > maxDiff)) {
                max_jump[i] = j;
                ++i;
            }
            else{
                ++j;
            }
        }

        int l = log2(n);
        vector<vector<int>> up(n, vector<int>(l + 1));

        for(int i = 0; i < n; ++i) {
            up[i][0] = max_jump[i] == i ? -1 : max_jump[i];
        }

        for(int j = 1; j <= l; ++j) {
            for(int i = 0; i < n; ++i) {
                up[i][j] = up[i][j - 1] == -1 ? -1 : up[up[i][j - 1]][j - 1];
            }
        }

        vector<int> ans;
        ans.reserve(m);

        for(auto q : queries) {
            int x = org_to_rel[q[0]];
            int y = org_to_rel[q[1]]; 

            if(x > y) swap(x, y);
           
            if (x == y) {
                ans.push_back(0);
                continue;
            }

            int sum = 0, i = x;
            for(int j = l; j >= 0; --j){
                if(up[i][j] != -1 && up[i][j] < y) {
                    i = up[i][j];
                    sum += (1 << j);
                }
            }
            if (up[i][0] != -1 && up[i][0] >= y) ans.push_back(sum + 1);
            else ans.push_back(-1);
        }

        return ans;
    }
};