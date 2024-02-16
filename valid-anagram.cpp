//easy

class Solution {

public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false ;
        }

        map<char , int> smap , tmap;

        for(int i = 0 ; i < s.length() ; i++){

            smap[s[i]]++ ;
            tmap[t[i]]++ ;
        }

        for(auto i : smap){
            if(smap[i.first] != tmap[i.first]){
                return false ;
            }
        }

        return true ;
    
    }
};