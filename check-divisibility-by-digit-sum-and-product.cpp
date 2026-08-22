class Solution {
public:
    bool checkDivisibility(int n) {
        int d_sum = 0;
        int d_prod = 1;
        int n_orig = n;

        while(n != 0){
            int rem = n % 10;
            n /= 10;

            d_sum += rem;
            d_prod *= rem;
        } 

        return (n_orig % (d_sum + d_prod)) == 0;
    }
};