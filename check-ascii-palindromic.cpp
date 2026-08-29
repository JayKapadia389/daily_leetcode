class Solution {
private:
bool isOpp(char a, char b) {
    int i = 1 << 7, j = 1;

    for(int c = 0; c < 8; ++c){
        bool bit1 = (a & i) != 0;
        bool bit2 = (b & j) != 0;
        
        if(bit1 != bit2){
            return false;
        }
        i >>= 1;
        j <<= 1;
    }

    return true;
}
    
public:
    bool isPalindromic(string s) {
        int n = s.length();
        
        for(int i = 0; i <= n/2; ++i){
            if(!isOpp(s[i], s[n - i - 1])){
                return false;
            }
        }

        return true;
    }
};