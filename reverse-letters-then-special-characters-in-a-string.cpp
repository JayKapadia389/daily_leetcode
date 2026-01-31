// O(n) time, O(1) space

class Solution {
public:
    string reverseByType(string s) {
        int i = 0, j = s.length() - 1;

        // lower-case english letters
        while(i < j){
            while(!isalpha(s[i]) && i != j){
                ++i;
            }
            while(!isalpha(s[j]) && i != j){
                --j;
            }
            swap(s[i++], s[j--]);
        }

        // special chars
        i = 0, j = s.length() - 1;
        while(i < j){
            while(isalpha(s[i]) && i != j){
                ++i;
            }
            while(isalpha(s[j]) && i != j){
                --j;
            }
            swap(s[i++], s[j--]);
        }
        return s;
    }
};