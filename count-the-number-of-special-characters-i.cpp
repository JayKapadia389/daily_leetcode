class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26, 0);
        vector<bool> upper(26, 0);
        int cnt = 0;

        for(auto ch : word){
            if(ch >= 'a' && ch <= 'z'){
                lower[ch - 'a'] = 1;
            }
            else{
                upper[ch - 'A'] = 1;
            }
        }

        for(int i = 0; i < 26; ++i){
            if(lower[i] == true && upper[i] == true){
                ++cnt;
            }
        }

        return cnt;
    }
};