class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length())
        return false; 

        int n = s.length() ;
        bool flag = 0 ;

        for(int i = 0 ; i < n ; i++){

            flag = 0 ;

            for(int j = 0 ; j < n ; j++){

                int idx ;

                if(i+j < n){
                    idx = i+j ;
                }
                else{
                    idx = (i+j)-n ;
                }

                if(s[j] != goal[idx]){
                    flag = 1 ;
                    break ;
                }

            }
            if(!flag){
                return true ;
            }

        }

        return false ;
        
    }
};