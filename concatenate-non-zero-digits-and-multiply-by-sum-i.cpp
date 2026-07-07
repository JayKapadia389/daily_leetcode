class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0, mul = 1;
        int sum = 0;

        while(n != 0) {
            int rem = n % 10;
            n /= 10;
            
            sum += rem;

            if(rem != 0) {
                rem *= mul;
                x = rem + x;
                mul *= 10;
            }
        }

        return static_cast<long long>(x) * sum;
    }
};