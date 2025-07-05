class Solution {
public:

    char getchar(int& rem){
        if(rem >= 0 && rem <= 9){
            return rem + '0' ; 
        }
        else{
            return static_cast<char>(rem + 55) ; 
        }
    }

    string hex(int& n , int p ,int base ){
        int m = pow(n,p) , rem ; 
        string s = "" ; 

        while(m){
            rem = m % base ; 
            s = getchar(rem) + s ; 
            m /= base ; 
        }
        return s ;
    }
    
    string concatHex36(int n) {
        return hex(n,2,16) + hex(n,3,36) ;
    }
};