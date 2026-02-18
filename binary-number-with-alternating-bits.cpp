// Solution 1:
class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool last = n & 1;
        n >>= 1;

        while(n != 0){
            if(last == (n & 1)){
                return false;
            }
            last = !last;
            n >>= 1;
        }

        return true;
    }
};

// Solution 2:
function bitSolution(number){
    //      10101010101
    //  +    1010101010    ( number >> 1 )
    //  ---------------
    //  =   11111111111
    //  &  100000000000
    //  ---------------
    //  =             0    ( power of two )
    let tmp = ( number >> 1 ) + number;
    return (tmp & tmp + 1) === 0;
}