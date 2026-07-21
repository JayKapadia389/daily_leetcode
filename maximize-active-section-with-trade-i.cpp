class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int active = 0;
        int n = s.length();
        int mx = 0;
        int a = 0, b = 0;

        for(int i = 0; i < n; ++i) {
            if(s[i] == '1'){
                ++active;
            }
            else { // 0
                if(i == 0 || s[i - 1] == '1'){
                    mx = max(mx, a + b);
                    a = b;
                    b = 1;
                }
                else{
                    ++b;
                }
            }
        }

        if(a != 0){
            mx = max(mx, a + b);
        }

        return active + mx;
    }
};