class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int k = 1;
        int n = nums.size();
        vector<int> prefix(n,1);
        vector<int> postfix(n,1); 

        for(int i=1; i<n; ++i){
            if(nums[i] > nums[i-1]) prefix[i] = prefix[i-1] + 1;
        }

        for(int i=n-2; i>=0; --i){
            if(nums[i] < nums[i+1]) postfix[i] = postfix[i+1] + 1;
        }

        for(int i = 0; i < n-1; ++i){
            k = max(k, min(prefix[i], postfix[i+1]));
        }

        return k;
    }
};