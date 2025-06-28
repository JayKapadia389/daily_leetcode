class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n == 1){
            return nums[0] ; 
        } 
        vector<int> maxValues(n , 0) ; 

        if(n > 2){
            maxValues[2] = nums[0] ; 
        }

        for(int i = 3 ; i < n ; ++i){
            maxValues[i] = max(nums[i-3] + maxValues[i-3],
                                nums[i-2] + maxValues[i-2]) ; 
        }

        return max(nums[n-1] + maxValues[n-1],
                                nums[n-2] + maxValues[n-2]);        
        
    }
};