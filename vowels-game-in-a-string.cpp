class Solution {
public:
    bool doesAliceWin(string s) {
        return s.find_first_of("aeiou") != string::npos;
    }
};