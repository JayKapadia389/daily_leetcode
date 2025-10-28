class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        vector<int> pre(n,0);

        for(int i = 1; i < n; ++i){
            pre[i] = pre[i-1] + nums[i-1];
        }

        int post = 0;
        for(int i = n-1 ; i >= 0; --i){
            if(nums[i] == 0){
                if(abs(pre[i] - post) == 0){
                    ans += 2;
                }
                else if(abs(pre[i] - post) == 1){
                    ans += 1;
                }
            }
            post += nums[i];
        }

        return ans;
    }
};