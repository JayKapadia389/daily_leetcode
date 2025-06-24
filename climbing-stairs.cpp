class Solution {
public:
    int climbStairs(int n) {
        int f = 1 , s = 2 , temp ; 

        if(n == f){
            return f ; 
        }
        if(n == s){
            return s ; 
        }

        for(int i = 3; i <= n ; ++i){
            temp = f ; 
            f = s ; 
            s += temp ;
        }

        return s ; 
    }
};