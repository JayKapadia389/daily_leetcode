class Solution {
public:
    int maxProduct(int n) {
        int mx1 = INT_MIN, mx2 = INT_MIN;

        while(n != 0){
            int d = n % 10;
            n /= 10;

            if(d >= mx2){
                mx1 = mx2;
                mx2 = d;
            }
            else if(d > mx1){
                mx1 = d;
            }
        }

        return mx1 * mx2;
    }
};