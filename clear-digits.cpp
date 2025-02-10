class Solution {
public:

    int finddigit(string s1) {
        for (int i = 0; i < s1.length(); ++i) {
            if ((s1[i] - '0') >= 0 && (s1[i] - '0') <= 9) {
                return i;
            }
        }
        return -1;
    }

    void modify(string& s1, int idx) {
        string s2 = "";

        s2 += s1.substr(0, idx - 1);
        s2 += s1.substr(idx + 1, s1.length() - idx - 1);

        s1 = s2;
    }

    string clearDigits(string s) {

        string s1 = s;

        while (true) {

            int idx = finddigit(s1);

            if (idx == -1) {
                break;
            }
            else {
                modify(s1, idx);
            }

        }

        return s1;

    }
};