class Solution {
public:
    bool isPalindrome(string s) {

        if(s.length() == 0){
            return true ;
        }

        transform(s.begin() , s.end() , s.begin() , ::tolower);

        int l = 0 , r = s.length() - 1; // check

        while(l < r){

            if(!((s[l] >= 48 && s[l] <= 57) || (s[l] >= 97 && s[l] <= 122))){
                l++ ;
                continue ;
            }
            if(!((s[r] >= 48 && s[r] <= 57) || (s[r] >= 97 && s[r] <= 122))){
                r-- ;
                continue ;
            }

            if(s[l] == s[r]){
                l++ ;
                r-- ;
            }
            else{
                return false ;
            }

        }

        return true ;

    }
};