class Solution {
string ans_;
int n_;

bool recc(vector<char> path, vector<int>& freq, string& target, bool big){
    if(path.size() == n_){
        if(big){
            ans_ = string(path.begin(), path.end());
            return true;
        }
        else{
            return false;
        }
    }

    int i = path.size();

    for(int j = 0; j < 26; ++j){
        if(freq[j] == 0) continue;
        if(!big && (j + 'a') < target[i]) continue;

        path.push_back(j + 'a');
        --freq[j];

        bool newBig = big || ((j + 'a') > target[i]); 

        if(recc(path, freq, target, newBig)) return true;

        ++freq[j];
        path.pop_back();
    }

    return false;
}

public:
    string lexGreaterPermutation(string s, string target) {
    ans_ = "";
    n_ = target.size();
    vector<int> freq(26,0);

    for(auto ch : s){
        ++freq[ch - 'a'];
    }

    vector<char> path;
    recc(path, freq, target, false);


    return ans_;
    }
};