class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0)
            return false;
        
        long long comp = 1;
        long long one = 1;
        while(comp <= ((one << 31) - 1)){
            if(comp == n)
                return true;
            comp*=3;
        }
        return false;
    }
};