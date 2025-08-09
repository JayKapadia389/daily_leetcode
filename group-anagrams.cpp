class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;

        for(auto str : strs){
            vector<int> freq_vec(26,0);

            for(auto ch : str){
                ++freq_vec[ch - 'a'];
            }

            m[freq_vec].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto [_,vec] : m){
            ans.push_back(vec);
        }
        return ans;
    }
};