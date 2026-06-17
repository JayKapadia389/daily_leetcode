class Solution {
public:
    char processStr(string s, long long k) {
        ++k;
        int n = s.size();
        vector<long long> curr_len(n);

        curr_len[0] = (s[0] >= 'a' && s[0] <= 'z')? 1 : 0;

        for(int i = 1; i < n; ++i){
            if(s[i] >= 'a' && s[i] <= 'z'){
                curr_len[i] = curr_len[i-1] + 1; 
            }
            else if(s[i] == '*'){
                curr_len[i] = max(curr_len[i-1] - 1, (long long) 0); 
            }
            else if(s[i] == '#'){
                curr_len[i] = curr_len[i-1] * 2; 
            }
            else{
                curr_len[i] = curr_len[i - 1]; 
            }
        }

        if(curr_len[n - 1] < k) return '.';

        for(int i = n - 1; i >= 0; --i){
            long long len = curr_len[i];

            if(s[i] >= 'a' && s[i] <= 'z'){
                if(k == len){
                    return s[i];
                }
            }
            else if(s[i] == '#'){
                if(len/2 < k){
                    k = len/2 - (len - k);
                }
            }
            else if(s[i] == '%'){
                k = len - k + 1;
            }
        }

        return '.';
    }
};