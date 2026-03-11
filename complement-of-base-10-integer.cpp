class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;

        bool found = 0;
        int mask = 1 << 30;

        while(mask != 0){
            if((n & mask) != 0){
                found = 1;
            }
            if(found){
                n ^= mask;
            }
            mask >>= 1;
        }

        return n;
    }
};