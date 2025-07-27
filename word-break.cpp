class Solution {
private:
    vector<bool> dp_;
    vector<bool> visited_;
    string s_;
    unordered_set<string> words_;

    bool dp(int i){
        if(i == -1){
            return true;
        }

        if(!visited_[i]){
            visited_[i] = 1;
            for(int j = 0 ; (j < 20 && (i-j) >= 0); ++j){
                if(words_.find(s_.substr(i-j, j+1)) != words_.end() && dp(i-j-1)){
                    dp_[i] = 1;
                    break;
                }
            }
        }
        return dp_[i];
    }

public:

    bool wordBreak(string s, vector<string>& wordDict) {
        dp_ = vector<bool>(s.length(), 0);
        visited_ = vector<bool>(s.length(), 0);
        s_ = s;
        words_.clear();

        for(auto word : wordDict){
            words_.insert(word);
        }
        
        return dp(s.length() - 1);
    }
};