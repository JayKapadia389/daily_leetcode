class Solution {
public:
    int numSub(string s) {
        int prev = (s[0] == '0') ? 0 : 1;
        int ans = prev;
        int mod = 1e9 + 7;

        for(int i = 1; i < s.length(); ++i){
            if(s[i] == '1'){
                ans = (ans + (++prev)) % mod; 
            }
            else{
                prev = 0;
            }
        }

        return ans;
    }
};