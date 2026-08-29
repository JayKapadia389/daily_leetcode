class Solution {
private:
int n_;
string target_;
char odd_freq_char_;

bool recc(int idx, string& temp, string& ans, vector<int>& freq, bool lets_go) {
    if(idx == (n_/2)){
        if(odd_freq_char_ != '*'){
            temp.push_back(odd_freq_char_);
        }

        for(int i = n_/2 - 1; i >= 0; --i){
            temp.push_back(temp[i]);
        }

        if(temp > target_){
            ans = temp;
            return true;
        }
        else {
            temp = temp.substr(0, n_/2);
            return false;
        }
    }

    for(int i = 0; i < 26; ++i){
        char curr_ch = i + 'a';

        if(freq[i] != 0){
            if(lets_go){
                temp.push_back(curr_ch);
                --freq[i];
                recc(idx + 1, temp, ans, freq, 1);
                return true;
            }
            else {
                if(curr_ch == target_[idx]){
                    temp.push_back(curr_ch);
                    --freq[i];
                    if(recc(idx + 1, temp, ans, freq, 0)){
                        return true;
                    }
                    ++freq[i];
                    temp.pop_back();
                }
                else if(curr_ch > target_[idx]){
                    temp.push_back(curr_ch);
                    --freq[i];
                    recc(idx + 1, temp, ans, freq, 1);
                    return true;
                }
            }
        }
    }

    return false;
}

public:
    string lexPalindromicPermutation(string s, string target) {
        n_ = s.length();
        target_ = target;
        string ans = "", temp = "";
        ans.reserve(n_);
        temp.reserve(n_);

        vector<int> freq(26, 0);

        for(auto ch : s) {
            ++freq[ch - 'a'];
        }

        odd_freq_char_ = '*';
        for(int i = 0; i < 26; ++i) {
            if(freq[i] % 2 != 0){
                if(odd_freq_char_ == '*'){
                    odd_freq_char_ = i + 'a';
                    freq[i] /= 2;
                }
                else {
                    return "";
                }
            }
            else{
                freq[i] /= 2;
            }
        }

        recc(0, temp, ans, freq, 0);

        return ans;
    }
};