class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0)
            return false;

        for(int i = 0; i <= 30; i += 2){
            if((1 << i) == n){
                return true;
            }
        } 
        return false;
    }
};