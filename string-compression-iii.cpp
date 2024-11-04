class Solution {
public:
    string compressedString(string word) {

        int c = 1 ;
        string comp = ""; 
        int n = word.length() ;

        for(int i = 0 ; i <= n-2 ; i++){

            if(word[i] == word[i+1] ){

                if(c == 9){
                    comp += to_string(c) ;
                    comp += word[i] ; 
                    c = 1 ;
                }
                else{
                    ++c ;
                }

            }
            else{
                comp += to_string(c) ;
                comp += word[i] ; 
                c = 1 ;
            }

        }

        comp += to_string(c) ;
        comp += word[n-1] ;

        return comp ;
        
    }
};