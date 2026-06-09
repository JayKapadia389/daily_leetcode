class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn = INT_MAX, mx = INT_MIN;

        for(auto num : nums){
            mn = min(mn, num);
            mx = max(mx, num);
        }

        return static_cast<long long>(k) * (mx - mn);
    }
};