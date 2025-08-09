class Solution {
public:
    string frequencySort(string s) {
        map<char,int> freq;
        for(auto ch : s){
            ++freq[ch];
        }

        sort(s.begin(), s.end(), [&freq](char a, char b){
            if(freq[a] == freq[b]){
                return a < b;
            }
            return freq[a] > freq[b];
        });

        return s;
    }
};