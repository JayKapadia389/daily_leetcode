class Solution {
public:

    // boolean unq(vector<int> temp , vector<vector<int>> ans){

    // }

    void core(vector<int> nums , int i , vector<int> temp , vector<vector<int>> &ans){

        if(i == nums.size()){

            vector<vector<int>>::iterator it = find(ans.begin() , ans.end() , temp);

            if(it == ans.end()){
                ans.push_back(temp) ;
            }
            return ;
        }

        core(nums , i+1 , temp , ans) ;

        temp.push_back(nums[i]) ;

        core(nums , i+1 , temp , ans) ;

        return ;

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<int> temp ;
        vector<vector<int>> ans ;

        core(nums , 0 , temp , ans) ;

        return ans ;

    }
};