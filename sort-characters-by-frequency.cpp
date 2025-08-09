class Solution {
public:
    static bool comp(pair<char, int> a, pair<char, int> b){
        return a.second > b.second;
    }

    string frequencySort(string s) {

        map<char,int> freq_m;

        for(auto ch : s){
            ++freq_m[ch];
        }

        vector<pair<char, int>> v;
        for(auto [ch, freq] : freq_m){
            v.push_back({ch,freq});
        }

        sort(v.begin(), v.end(), comp);

        string ans;
        ans.reserve(s.size());

        for(auto p : v){
            for(int i = 0; i < p.second; ++i){
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};