class Solution {
public:

    map<int , bool> m ;

    bool core(int n){

        if(n == 1){
            return true ;
        }

        if(m[n]){
            return false ;
        }

        m[n] = 1;

        string s = to_string(n) ;
        int acc = 0 ;
        int num ;

        for(int i = 0 ; i < s.length() ; i++){
            num = s[i] - '0' ;
            acc+= num*num ;
        }

        return core(acc) ;

    }

    bool isHappy(int n) {

        m.clear() ;

        return core(n) ;
        
    }
};