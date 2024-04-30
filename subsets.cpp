class Solution {
public:

    void core(vector<int> nums , int i , vector<int> temp , vector<vector<int>> &ans){

        if(i == nums.size()){
            ans.push_back(temp) ;
            return ; 
        }

        core(nums , i+1 , temp , ans) ;
        temp.push_back(nums[i]) ;
        core(nums , i+1 , temp , ans) ;

        return ;

    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans ;
        vector<int> temp ;

        core(nums , 0 , temp,  ans) ;

        return ans ;
        
    }
};