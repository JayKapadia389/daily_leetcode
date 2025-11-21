class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0, n = s.length();
        vector<vector<bool>> grid(26, vector<bool>(26,0));
        vector<vector<bool>> prefix(n, vector<bool>(26, 0));
        vector<bool> right(26, 0);

        for(int i = 1; i < n; ++i){
            prefix[i] = prefix[i-1];
            prefix[i][s[i-1] - 'a'] = 1;
        }

        for(int i = n-2; i >= 0; --i){
            right[s[i+1] - 'a'] = 1;

            for(int j = 0; j < 26; ++j){
                if(prefix[i][j] && right[j]){
                    if(!grid[s[i] - 'a'][j]) ++ans;
                    grid[s[i] - 'a'][j] = 1;
                }
            }
        }

        return ans;
    }
};

// someone's solution
//
// int countPalindromicSubsequence(string s) {
//     int first[26] = {[0 ... 25] = INT_MAX}, last[26] = {}, res = 0;
//     for (int i = 0; i < s.size(); ++i) {
//         first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
//         last[s[i] - 'a'] = i;
//     }
//     for (int i = 0; i < 26; ++i)
//         if (first[i] < last[i])
//             res += unordered_set<char>(begin(s) + first[i] + 1, begin(s) + last[i]).size();
//     return res;
// }