class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;

        bool b = 0;
        for(int i = 0; i < 31; ++i){
            if(((1 << i) & n)){
                if(b == 1){
                    return false;
                }
                else{
                    b = 1;
                }
            }
        }
        return true;
    }
};