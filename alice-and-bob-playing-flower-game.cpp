class Solution {
public:
    long long flowerGame(int n, int m) {
        long long n_odd = n % 2 == 0 ? n/2 : (n+1)/2 ;
        long long n_even = n/2;
        long long m_odd = m % 2 == 0 ? m/2 : (m+1)/2;
        long long m_even = m/2;
        return n_odd * m_even + n_even * m_odd ; 
    }
};