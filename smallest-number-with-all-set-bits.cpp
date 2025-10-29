class Solution {
public:
    int smallestNumber(int n) {
        int i = 1;

        while(true){
            if(i >= n){
                return i;
            }
            i <<= 1;
            i += 1;
        }
        return 0;
    }
};