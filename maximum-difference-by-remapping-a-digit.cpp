class Solution {
public:

    int minimum(int num){
        string s = to_string(num) ;
        char ch = s[0] ; 

        for(int i = 0 ; i < s.length() ; ++i){
            if(s[i] == ch){
                s[i] = '0' ; 
            }
        }

        return stoi(s) ; 
    }

    int maximum(int num){
        string s = to_string(num) ;
        char ch;

        for(auto i : s){
            if(i != '9'){
                ch = i ;
                break ; 
            }
        }

        for(int i = 0 ; i < s.length() ; ++i){
            if(s[i] == ch){ 
                s[i] = '9';
            }
        }

        return stoi(s) ; 
    }

    int minMaxDifference(int num) {

        return maximum(num) - minimum(num) ; 
        
    }
};