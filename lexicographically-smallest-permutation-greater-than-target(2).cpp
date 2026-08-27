class Solution {
private:
int n_;
string target_;

bool populate_answer(int idx, string& temp, string& ans, bool lets_go, vector<int>& freq) {
    if(idx == n_) {
        if(temp > target_) {
            ans = temp;
            return true;
        }
        else {
            return false;
        }
    }

    for(int i = 0; i < 26; ++i) {
        char ch = i + 'a';

        if(freq[i] != 0) {
            if(lets_go){
                temp.push_back(ch);
                --freq[i];
                populate_answer(idx + 1, temp, ans, 1, freq);
                return true;
            }
            else{
                if(ch == target_[idx]){
                    temp.push_back(ch);
                    --freq[i];
                    if(populate_answer(idx + 1, temp, ans, 0, freq)) {
                        return true;
                    }
                    else {
                        temp.pop_back();
                        ++freq[i];
                    }
                }
                else if(ch > target_[idx]) {
                    temp.push_back(ch);
                    --freq[i];
                    populate_answer(idx + 1, temp, ans, 1, freq);
                    return true;
                }
            }
        }
    }

    return false;
}

public:
    string lexGreaterPermutation(string s, string target) {
        n_ = s.length();
        target_ = target;
        string temp = "", ans = "";
        temp.reserve(n_);
        ans.reserve(n_);
        vector<int> freq(26, 0);

        for(auto ch : s) {
            ++freq[ch - 'a'];
        }

        populate_answer(0, temp, ans, 0, freq);

        return ans;
    }
};