class Solution {
private:
bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ;
}

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> s;
        unordered_map<string, pair<string,int>> m;
        int n = wordlist.size();
        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for(int i = 0; i < n; ++i){
            string str = wordlist[i];
            s.insert(str);
            string lc;

            std::transform(str.begin(), str.end(), lc.begin(), ::tolower);

            if(m.find(lc) == m.end()){
                m[lc] = {str, i};
            }
        }

        int size = queries.size();
        for(int i = 0; i < size; ++i){
            string str = queries[i];
            if(s.find(str) != s.end()){
                continue;
            }

            string lc;
            std::transform(str.begin(), str.end(), lc.begin(), ::tolower);

            if(m.find(lc) != m.end()){
                queries[i] = m[lc].first;
            }
            else{ // vowel match
                string replacement = "";
                int idx = INT_MAX;
                int len = lc.length();

                for(int j = 0; j < len; ++j){
                    if(isVowel(lc[j])){

                        for(int k = 0; k < 5; ++k){
                            char vowel = vowels[k];
                            string new_lc = lc;
                            new_lc[j] = vowel;

                            if(m.find(new_lc) != m.end()){
                                if(m[new_lc].second < idx){
                                    idx = m[new_lc].second;
                                    replacement = m[new_lc].first;
                                }
                            } 
                        }
                            
                    }
                }

                queries[i] = replacement;
            }
        }

        return queries;
    }
};