class Solution {
public:
    int totalMoney(int n) {
        int a = n/7;
        int b = n%7;
        return 28*a + (7*(a-1)*a)/2 + a*b + (b*(b+1))/2;
    }
};