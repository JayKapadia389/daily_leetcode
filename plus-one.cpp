class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

            vector<int> ans(digits.size()+1 , 0) ;
        for(int i = digits.size()-1 ; i >= -1 ; i--){


            if(i == -1){

                ans[0] = 1 ;
                return ans ;

            }
            else{

                if(digits[i] < 9){
                    digits[i] += 1;
                    return digits ;
                }
                else{
                    digits[i] = 0 ;
                }

            }
            
        }

        return ans ;
        
    }
};