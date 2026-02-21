class Solution {
public:
    bool isPrime(const int& num){
        if(num == 1) return false;
        
        for(int i = 2; i*i <= num; ++i){
            if(num % i == 0){
                return false;
            }
        }
        return true;
    }

    int countPrimeSetBits(int left, int right) {
        int cnt = 0;
        for(int i = left; i <= right; ++i){
            if(isPrime(__builtin_popcount(i))){
                ++cnt;
            }
        }
        return cnt;
    }
};