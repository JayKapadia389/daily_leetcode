class Solution {
public:
    int numDistinct(string s, string t) {
        // i,j -> i + 1, j
        // i,j -> i + 1, j + 1 or i + 1, j

        // i , m -> 1 
        // n , j -> 0
        // n , m -> 1

        int m = s.length(), n = t.length();
        vector<uint> prev(n + 1, 0), curr(n + 1, 0);
        prev[n] = 1;
        curr[n] = 1;

        for(int i = m - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j) {
                curr[j] = prev[j];

                if(t[j] == s[i]) {
                    curr[j] += prev[j + 1];
                }a
            }

            swap(curr, prev);
        }

        return prev[0];
    }
};