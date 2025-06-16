class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int ans = -1, mn = nums[0] , n = nums.size() , diff;

        for(int i = 1; i < n ; ++i){
            diff = nums[i] - mn ; 
            if(diff >0){
                ans = max(ans, diff) ; 
            }
            mn = min(mn , nums[i]) ; 
        } 
        return ans ; 
        
    }
};