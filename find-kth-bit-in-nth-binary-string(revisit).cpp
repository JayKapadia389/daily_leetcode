class Solution {
public:
    char findKthBit(int n, int k) {
        int last = pow(2,20) - 2;
        bool flip = 0;
        k -= 1;
        
        while(k != 0){
            if(last - k < k){
                k = last - k;
                flip = !flip;
            }
            else if((last - k) == k){
                return flip? '0' : '1';
            }
            last = last/2 -1;
        }

        return flip? '1' : '0';
    }
};