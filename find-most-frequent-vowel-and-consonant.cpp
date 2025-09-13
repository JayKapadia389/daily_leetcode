class Solution {
private:
bool isVowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

public:
    int maxFreqSum(string s) {
        int max_vowel_freq = 0;
        int max_con_freq = 0;
        vector<int> freq(26,0);

        for(auto ch : s){
            ++freq[ch - 'a'];

            if(isVowel(ch)){
                max_vowel_freq = max(max_vowel_freq , freq[ch - 'a']);
            }
            else{
                max_con_freq = max(max_con_freq , freq[ch - 'a']);
            }
        }

        return max_vowel_freq + max_con_freq;
    }
};