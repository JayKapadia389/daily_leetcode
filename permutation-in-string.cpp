class Solution {
public:

    bool isPerm(map<char,int> m1 , map<char,int> m2 ){

        for(auto i : m1){

            if(i.second != m2[i.first]){
                return false ;
            }
        }

        return true ;
    }

    bool checkInclusion(string s1, string s2) {

        int m = s2.length() , n = s1.length() ;

        map<char , int >  m1 ; 
        
        for(int i = 0 ; i < s1.length() ; i++){
            m1[s1[i]]++ ;
        }

        for(int i = 0 ; i <= (m-n) ; i++){

            map<char, int> m2 ;

            for(int j = i ; j < i+n ; j++){
                m2[s2[j]]++ ;
            }

            if(isPerm(m1 , m2)){
                return true ;
            }
        }

        return false ;
    }
};