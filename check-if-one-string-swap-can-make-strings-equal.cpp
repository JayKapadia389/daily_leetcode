class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        if (s1 == s2)
            return true;

        char s1f, s1s, s2f, s2s;
        int c = 0, n = s1.length();

        for (int i = 0; i < n; i++) {
            if (s1[i] != s2[i]) {
                ++c;

                if (c == 1) {
                    s1f = s1[i];
                    s2f = s2[i];
                }
                else if (c == 2) {
                    s1s = s1[i];
                    s2s = s2[i];
                }
                else {
                    break;
                }
            }
        }

        if (c == 2) {
            if (s1f == s2s && s1s == s2f) {
                return true;
            }
        }
        return false;

    }
};