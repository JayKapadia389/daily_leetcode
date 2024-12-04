class Solution {
public:

    bool possible(char c1, char c2) {

        if (c1 == c2)
            return true;

        if (c2 == 'a' && c1 == 'z')
            return true;

        if (c1 + 1 == c2)
            return true;

        return false;

    }

    bool canMakeSubsequence(string str1, string str2) {

        int n = str1.length(), m = str2.length();

        if (m > n)
            return false;

        int i = 0, j = 0;

        while (true) {

            if (j == m)
                return true;

            if (i == n)
                return false;

            if (possible(str1[i], str2[j])) {
                ++j;
            }
            ++i;
        }

    }
};