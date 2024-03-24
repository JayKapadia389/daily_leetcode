class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.length() == 0){
            return 0 ;
        }  

        int mx = 1 , len = 1 ;

        int begin = 0 , r = begin;

        for (int curr = 1 ; curr < s.length() ; curr++ ){

            r = begin ;

            while(r != curr){

                if(s[r] == s[curr]){
                    break ;
                }

                r++ ;

            }

            if(r != curr){
                len -= ((r-begin) + 1) ;

                begin = r+1 ; 
            }
            
            len++ ;

            mx = max(mx , len) ;
        }

        return mx ;
    }
};