class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;

        for(auto ch : s){
            if(ch == ' ' || (ch >= '0' && ch <= '9')) continue;
            
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                ++v;
            }
            else{
                ++c;
            }
        }

        if(c == 0) return 0;

        return floor(v/c);
    }
};