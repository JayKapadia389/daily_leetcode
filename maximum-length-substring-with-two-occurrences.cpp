class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len = 0, n = s.length();
        vector<int> freq(26, 0);

        for(int i = 0, j = 0; j < n; ++j) {
            char curr_ch = s[j];
            ++freq[curr_ch - 'a'];

            while(freq[curr_ch - 'a'] > 2){
                --freq[s[i] - 'a'];
                ++i;
            }

            len = max(len, j - i + 1);
        }

        return len;
    }
};