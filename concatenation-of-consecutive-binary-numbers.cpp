class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        int m = 1e9 + 7;

        for(int i = 1; i <= n; ++i){
            vector<bool> s;
            int num = i;

            while(num > 0){
                s.push_back(num & 1);
                num >>= 1;
            }

            while(!s.empty()){
                ans <<= 1;
                ans += s.back();
                s.pop_back();
                ans %= m;
            }
        }

        return ans;
    }
};