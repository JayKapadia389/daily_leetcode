class Solution {
public:

    bool valid(map<char, int> m , int k , int l , int r){

        int mx = 0 ;

        for(auto i : m){
            mx = max(mx , i.second) ;
        }

        if(((r-l+1)-mx) <= k ){
            return true ;
        }
        return false ;
    }

    int characterReplacement(string s, int k) {

        int res = 0 ;

        int l = 0 , r = 0 ;
        map<char , int > m ;
        m[s[0]]++ ;

        while(true){

            if(valid(m , k , l , r)){
                res++ ;
            }

            else{
                m[s[l]]-- ;
                l++ ;
            }

            r++;
            if(r == s.length()){
                break ;
            }
            m[s[r]]++ ;

        } 

        return res ;
        
    }
};