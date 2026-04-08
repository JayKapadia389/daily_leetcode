int MOD = 1e9 + 7;

class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0, n = nums.size(), m = queries.size();

        for(const auto& q : queries){
            int l = q[0], r = q[1], k = q[2], v = q[3];

            for(int idx = l; idx <= r; idx += k){
                nums[idx] = ((long) nums[idx] * v) % MOD;
            }
        }

        for(auto num : nums){
            ans ^= num;
        }

        return ans;
    }
};