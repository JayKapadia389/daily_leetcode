class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length(), n = t.length();
        vector<uint> curr(n, 0);

        for(int i = m - 1; i >= 0; --i){
            for(int j = max(n - m + i, 0); j < n; ++j){
                if(s[i] == t[j]){
                    curr[j] += ((j + 1 < n) ? curr[j+1] : 1);
                }
            }
        }

        return curr[0];
    }
};