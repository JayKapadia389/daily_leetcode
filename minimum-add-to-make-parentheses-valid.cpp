class Solution {
public:
    int minAddToMakeValid(string s) {

        int c = 0 ; 
        int open = 0 ;
        int close = 0 ;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '('){
                open++ ;
            }
            else{
                close++ ;
            }

            if(close > open){
                c++ ;
                open++ ;
            }
        }

        c += (open - close) ;

        return c ;
        
    }
};