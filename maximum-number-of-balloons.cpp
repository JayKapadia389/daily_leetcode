class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> m;
        for(auto ch : text){
            ++m[ch];
        }
        return min({m['b'], m['a'], m['l'] / 2, m['o'] / 2, m['n']});
    }
};