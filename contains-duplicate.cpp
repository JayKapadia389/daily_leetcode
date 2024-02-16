//easy

class Solution {
public:

    bool containsDuplicate(vector<int>& nums) {

        map<int , bool >  exist ;
        
        for(int i = 0 ; i < nums.size() ; i++){

                if(exist[nums[i]]){
                    return true ;
                }
                exist[nums[i]] = 1 ;
            
        }

        return false ;
    }
};