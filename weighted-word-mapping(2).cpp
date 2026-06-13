class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans = "";
        ans.reserve(n);

        for(auto word : words){
            int w = 0;
            for(auto ch : word){
                w += weights[ch - 'a'];
            }
            int rem = w % 26;
            char mapped_ch = 'a' + (25 - rem); 
            ans += mapped_ch;
        }

        return ans;
    }
};