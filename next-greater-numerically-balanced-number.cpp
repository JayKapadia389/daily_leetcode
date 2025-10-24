class Solution {
private:
string n_str_;
int len_;
string next_;

bool fun(vector<int>& cnt,int idx, bool longer){
    if(idx == len_ + longer){
        if(next_ == n_str_){
            return false;
        }

        bool balanced = true;
        for(int i = 1; i <= 8; ++i){
            if(cnt[i] != 0 && cnt[i] != i){
                balanced = 0;
                break;
            }
        }

        return balanced;
    }

    for(int i = 1; i <= len_ + longer; ++i){
        if(cnt[i] == i){
            continue;
        }

        char i_ch = i + '0';
        next_[idx] = i_ch;

        if(!longer && next_.substr(0,idx+1) < n_str_.substr(0,idx+1)){
            continue;
        }

        ++cnt[i];
        if(fun(cnt, idx+1, longer)){
            return true;
        }
        --cnt[i];
    }
    next_[idx] = '0';
    return false;
}

public:
    int nextBeautifulNumber(int n) {
        if(n == 0) return 1;

        n_str_ = to_string(n); 
        len_ = log10(n) + 1;
        next_ = string(len_, '0');
        vector<int> cnt(9,0);

        if(fun(cnt,0,0)){
            return stoi(next_);
        }

        next_ += "0";
        fun(cnt, 0, 1);
        return stoi(next_);
    }
};