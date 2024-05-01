class Solution {
public:

    void core(vector<int>& candidates , int target , vector<int> temp , int i , vector<vector<int>> &ans){

        int sum = 0 ;

        for(int j = 0 ; j < temp.size() ; j++){
            sum += temp[j] ;
        }

        if(sum > target){
            return ;
        }
        else if(sum == target){
            ans.push_back(temp) ;
            return ;
        }

        for(int j = i ; j < candidates.size() ; j++){

            vector<int> tempNew = temp ;
            tempNew.push_back(candidates[j]) ;

            core(candidates , target , tempNew , j , ans) ;

        }

        return ;

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> temp ;
        vector<vector<int>> ans ;

        core(candidates , target , temp , 0 , ans ) ;

        return ans ;
        
    }
};