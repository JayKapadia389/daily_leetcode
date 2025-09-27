class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<char, int> freq;

        for(auto ch : s){
            ++freq[ch];
        }

        map<int, string> groups;
        
        for(auto it = freq.begin(); it != freq.end(); ++it){
            groups[it->second] += it->first;
        }

        int size = 0;
        string ans;
        
         for(auto it = groups.begin(); it != groups.end(); ++it){
            // groups[it.second] += it.first;
            if((it->second).length() >= size){
                size = (it->second).length();
                ans = (it->second);
            }
        }

        return ans;
    }
};