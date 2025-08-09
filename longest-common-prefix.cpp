class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = strs[0];

        for(auto s : strs){

            lcp = lcp.substr(0,s.size());
            if(lcp.empty()){
                break;
            }

            for(int i = 0; i < s.size() && lcp.size(); ++i){
                if(s[i] != lcp[i]){
                    lcp.erase(i);
                    break;
                }
            }
        }

        return lcp;
    }
};