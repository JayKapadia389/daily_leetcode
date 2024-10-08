class Solution {
public:

    int minSwaps(string s) {

        string s_ = s ;

        int open = 0 ;
        int close = 0 ;
        int c= 0 ;
        int l = s.length() ;

        for(int i = 0 ; i < s_.length() ; i++){

            if(s_[i] == '['){
               ++open ;
            }
            else{
                ++close ;
            }

            if(close > open){

                for(int j = l-1 ; j > i ; j--){
                    if(s_[j] == '['){

                        l = j ;

                        s_[i] = '[';
                        s_[j] = ']' ;
                        c++ ;
                        break ;
                    }
                }

                ++open;
                --close;
            }

        }

        return c ;
        
    }
};