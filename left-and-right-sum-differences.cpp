class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        ans[0] = 0;
        for(int i = 1; i < n; ++i){
            ans[i] = ans[i - 1] + nums[i - 1];
        }

        int right_sum = 0;
        for(int i = n - 1; i > 0; --i){
            int diff = abs(ans[i] - right_sum);
            ans[i] = diff;
            right_sum += nums[i];
        }

        ans[0] = right_sum;

        return ans;
    }
};