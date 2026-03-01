class Solution {
public:
    bool isVowel(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    string trimTrailingVowels(string s) {
        while(!s.empty() && isVowel(s.back())){
            s.pop_back();
        }

        return s;
    }
};