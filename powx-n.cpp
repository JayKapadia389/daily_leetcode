class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return (static_cast<double>(1)/x) ; 

        double ans;
        if(n%2 == 0){
           ans = myPow(x, n/2);
           ans*=ans;
        }
        else{
            ans = myPow(x , n - 1);
            ans*=x;
        }
        return ans;
    }
};