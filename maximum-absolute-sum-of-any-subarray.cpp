class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();
        vector<int> prefixSum(n);

        int sum = 0;

        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefixSum[i] = sum;
        }

        vector<int> maxVec(n);
        vector<int> minVec(n);
        int mx = 0, mn = 0;

        for (int i = 0; i < n; ++i) {
            mx = max(mx, prefixSum[i]);
            mn = min(mn, prefixSum[i]);

            maxVec[i] = mx;
            minVec[i] = mn;
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            ans = max(ans,
                max(abs(prefixSum[i] - maxVec[i]), abs(prefixSum[i] - minVec[i]))
            );
        }

        return ans;

    }
};