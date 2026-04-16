class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, int> first_occ;
        unordered_map<int, int> last_occ;
        unordered_map<int, int> left_recent_occ;
        unordered_map<int, int> right_recent_occ;
        int n = nums.size(), m = queries.size();
        vector<int> prefix(n, -1);
        vector<int> suffix(n, -1);
        vector<int> ans(m);

        for(int i = 0; i < n; ++i){
            if(first_occ.find(nums[i]) == first_occ.end()){
                first_occ[nums[i]] = i;
            }

            if(left_recent_occ.find(nums[i]) != left_recent_occ.end()){
                prefix[i] = left_recent_occ[nums[i]];
            }

            left_recent_occ[nums[i]] = i;
        }

        for(int i = n - 1; i >= 0; --i){
            if(last_occ.find(nums[i]) == last_occ.end()){
                last_occ[nums[i]] = i;
            }

            if(right_recent_occ.find(nums[i]) != left_recent_occ.end()){
                suffix[i] = right_recent_occ[nums[i]];
            }

            right_recent_occ[nums[i]] = i;
        }

        for(int q = 0; q < m; ++q){
            int dis = -1, i = queries[q], num = nums[i];
            if(prefix[i] != -1 && suffix[i] != -1){
                dis = min(i - prefix[i], suffix[i] - i);
            }
            else if(prefix[i] == -1 && suffix[i] != -1){
                dis = min(suffix[i] - i, i + (n - last_occ[num]));
            }
            else if(prefix[i] != -1 && suffix[i] == -1){
                dis = min(i - prefix[i], first_occ[num] + (n - i));
            }
            ans[q] = dis;
        }

        return ans;
    }
};