class Solution {
public:

    void core(vector<int> avail , vector<int> base , vector<vector<int>> &ans){

        if(avail.size() == 0){
            ans.push_back(base) ;
            return ;
        }

        for(int i = 0 ; i < avail.size() ; i++){

            vector<int> temp = avail ;
            vector<int>::iterator it = find(temp.begin() , temp.end() , avail[i]) ;
            temp.erase(it) ;

            vector<int> temp2 = base ;
            temp2.push_back(avail[i]) ;

            core(temp , temp2 , ans ) ;

        }

        return ;

    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> emp ;
        vector<vector<int>> ans ;

        core(nums , emp , ans) ;

        return ans ;
        
    }
};