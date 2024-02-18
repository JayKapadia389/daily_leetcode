class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int p = nums[0] ;
        vector<int> ans(nums.size() , 1) ;

        for(int i = 1 ; i < nums.size() ; i++){
            ans[i] = ans[i] * p ;

            p =  p * nums[i] ;
        }

        p = nums[nums.size()-1];

        for(int i= nums.size() - 2 ; i >= 0  ; i--){
            ans[i] = ans[i] * p ;

            p = p * nums[i] ;
        }
        return ans ;
    }
};