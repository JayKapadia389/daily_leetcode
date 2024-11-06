class Solution {
public:

    //map
    map<int , int> m ;

    int setbits(int num){

        if(m[num]){
            return m[num] ;
        }

        int num_ = num  , ans = 0;

        while(num_){
            ans+= (num_%2) ;

            num_ = num_/2 ;
        }

        m[num] = ans ;

        return ans ;

    }

    bool canSortArray(vector<int>& nums) {

        int n = nums.size() ;

        for(int i = 0 ; i< n-1 ; i++){

            for(int j = i+1  ; j < n ; j++){

                if(nums[i] > nums[j] && setbits(nums[i]) != setbits(nums[j])){
                    return false ;
                }

            }

        }

        return true ;
        
    }
};