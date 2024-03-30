class Solution {
public:

    bool fun(int f ,int l ,string s ,map<char,int> m1){

        map<char, int> m2 ;

         for(int i = f ; i <= l ; i++){
            m2[s[i]]++ ;
        }

        for(auto i : m1){
            if(m2[i.first] < i.second){
                return false ;
            }
        }

        return true ;
    }

    string minWindow(string s, string t) {

        int m = s.length() , n = t.length() ;

        if(m < n){
            return "" ;
        }

        map<char , int > m1 ;

        for(int i = 0 ; i < n ; i++){
            m1[t[i]]++ ;
        }

        for(int len = n ; len <= m ;len++ ){

            for(int f = 0 , l = len -1 ; l < m ;f++ , l++){

                if(fun(f , l , s , m1)){
                    return s.substr(f , len) ;
                }
                
            }

        }

        return "" ;
        
    }
};