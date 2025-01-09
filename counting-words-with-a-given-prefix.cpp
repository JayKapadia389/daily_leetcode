class Solution {
public:

    string pref_;

    bool isPref(string str) {
        if (pref_.length() > str.length()) {
            return false;
        }

        if (pref_ == str.substr(0, pref_.length())) {
            return true;
        }
        return false;
    }

    int prefixCount(vector<string>& words, string pref) {

        int c = 0;
        pref_ = pref;

        for (auto i : words) {
            if (isPref(i)) {
                ++c;
            }
        }

        return c;

    }
};