class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int m = 1e9 + 7;

        for(int i = 1; i <= n; ++i){
            stack<bool> s;
            int num = i;

            while(num > 0){
                s.push(num & 1);
                num >>= 1;
            }

            while(!s.empty()){
                ans <<= 1;
                ans += s.top();
                s.pop();
                ans %= m;
            }
        }

        return ans;
    }
};