class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int len = INT_MAX, n = s.length();
        string mn_str = "2";

        int cnt = 0;
        for(int i = 0, j = 0; j < n; ++j) {
            if(s[j] == '1'){
                ++cnt;
            }

            while(cnt > k || s[i] == '0') {
                if(s[i] == '1'){
                    --cnt;
                }
                ++i;
            }

            int curr_len = j - i + 1;
            if(cnt == k && (curr_len < len || (curr_len == len && (s.substr(i, curr_len) < mn_str)))) {
                mn_str = s.substr(i, curr_len);
                len = curr_len;
            }
        }

        return (mn_str == "2") ? "" : mn_str;
    }
};