class Solution {
public:

    string fun(int n){

        if(n == 1){
            return "0" ;
        }

        string sn_1 = fun(n-1) ;

        string acc = "" ;

        for(int i = sn_1.length()-1 ; i >= 0 ; i--){

            if(sn_1[i] == '0'){
                acc+= '1' ;
            }
            else{
                acc+= '0' ;
            }
        }

        return sn_1 + "1" + acc ;

    }

    char findKthBit(int n, int k) {

        string s = fun(n) ;

        return s[k-1] ;
        
    }
};