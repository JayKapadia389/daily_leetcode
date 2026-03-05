class Solution {
public:
    int minOperations(string s) {
        int z = 0, n = s.length();

        for(int i = 0; i < n; i++){
            if((i%2 == 0 && s[i] == '1') || (i%2 == 1 && s[i] == '0')){
                ++z;
            }
        }

        return min(z,n-z);
    }
};