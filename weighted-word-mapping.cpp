// contest
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string ans;
        ans.reserve(n);

        for(const auto& s : words){
            int weight = 0;

            for(const auto& ch : s){
                weight += weights[ch - 'a'];
            }

            ans += static_cast<char>('a' + (25 - (weight%26)));
        }

        return ans;
    }
};