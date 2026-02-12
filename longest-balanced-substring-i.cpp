// Solution 1 (280ms):
// 26n^2 time
// 26 space
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length(), len = 0;

        for(int i = 0; i < n; ++i){
            unordered_map<char, int> m;
            for(int j = i; j < n; ++j){
                bool b = 1;
                ++m[s[j]];
                int base = m[s[j]];
                for(auto it : m){
                    if(it.second != base){
                        b = 0;
                        break;
                    }
                }

                if(b){
                    len = max(len, j - i + 1);
                }
            }
        }

        return len;
    }
};

// Solution 2 (42ms):
// n^2 time
// 26 space
class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length(), ans = 0;

        for(int i = 0; i < n; ++i){
            vector<int> freq(26, 0);
            int mx_freq = 0;
            int distinct_char_cnt = 0;
            int mx_freq_cnt = 0;

            for(int j = i; j < n; ++j){
                int curr_freq = (++freq[s[j] - 'a']);

                if(curr_freq == 1){
                    ++distinct_char_cnt;
                }

                if(curr_freq > mx_freq){
                    mx_freq = curr_freq;
                    mx_freq_cnt = 1;
                }
                else if(curr_freq == mx_freq){
                    ++mx_freq_cnt;
                }
                
                if(distinct_char_cnt == mx_freq_cnt){
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};