class Solution {
public:
    int minChanges(string s) {

        int change = 0 ;
        int len = 1 ;
        int n = s.length() ;

        for(int i = 1 ; i < n ; i++){

            if(s[i] == s[i-1]){
                ++len ;
            }
            else{
                if(len%2 == 0){
                    len =1 ;
                }
                else{
                    ++change ;
                    len=0 ;
                }
            }
        }

        return change ;
        
    }
};