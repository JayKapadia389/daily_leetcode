class Solution {
public:

    bool isPrefixandSuffix(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();

        if (n1 > n2)
            return false;

        if (s1 == s2.substr(0, n1) && s1 == s2.substr(n2 - n1, n1)) {
            return true;
        }

        return false;

    }

    int countPrefixSuffixPairs(vector<string>& words) {

        int c = 0, n = words.size();

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPrefixandSuffix(words[i], words[j]))
                    ++c;
            }
        }
        return c;

    }
};