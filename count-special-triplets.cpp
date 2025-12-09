class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> left, right;
        int ans = 0, mod = 1e9 + 7;

        for(int i = 1; i < nums.size(); ++i){
            ++right[nums[i]];
        }

        for(int i = 0; i < nums.size()-1; ++i){
            int mid = nums[i];
            int dbl = mid * 2;

            ans = (ans + (left[dbl] * 1LL * right[dbl] % mod)) % mod;

            ++left[mid];
            --right[nums[i+1]];
        }

        return ans;
    }
};