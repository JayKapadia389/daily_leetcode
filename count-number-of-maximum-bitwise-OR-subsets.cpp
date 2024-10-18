class Solution {
public:

    int c ;
    int max ;
    int n ;

    void fun(vector<int> vec , int i , vector<int> &nums){

        if(i == n){

            if(vec.size() == 0){
                return ;
            }
            else{

                int acc = 0;

                for(auto i : vec){
                    acc = acc | i ;
                }

                if(acc > max){
                    max = acc ;
                    c = 1 ;
                }
                else if(acc == max){
                    c++ ;
                }
                
                return ;

            }

        }

        else{

            fun(vec , i+1 , nums) ;
            vec.push_back(nums[i]) ;
            fun(vec , i+1 , nums) ;

        }

        return ;

    }
    
    int countMaxOrSubsets(vector<int>& nums) {

        vector<int> v ;

        max = 0 ;
        c = 0 ;
        n = nums.size() ;

        fun(v , 0 , nums) ;

        return c ;
        
    }
};