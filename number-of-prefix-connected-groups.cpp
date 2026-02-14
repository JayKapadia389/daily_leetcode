// contest
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> m;
        int cnt = 0;

        for(auto str : words){
            if(str.length() < k){
                continue;
            }

            string prefix = str.substr(0, k);

            if(m.find(prefix) == m.end()){
                m[prefix] = 1;
            }
            else{
                int val = ++m[prefix];
                if(val == 2){
                    ++cnt;
                }
            }
        }

        return cnt;
    }
};