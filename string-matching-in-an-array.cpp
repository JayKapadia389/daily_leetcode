class Solution {
public:

    bool isSubStr(string x, string y) {

        int xlen = x.length(), ylen = y.length(), j = 0;

        if (xlen >= ylen)
            return false;

        for (int i = 0; i <= (ylen - xlen); ++i) {
            j = 0;

            while (j < xlen) {
                if (x[j] != y[i + j]) {
                    break;
                }
                ++j;
            }

            if (j == xlen) {
                return true;
            }
        }

        return false;

    }

    vector<string> stringMatching(vector<string>& words) {

        vector<string> ans;

        for (auto curr : words) {
            for (auto test : words) {
                if (curr != test) {
                    if (isSubStr(curr, test)) {
                        ans.push_back(curr);
                        break;
                    }
                }
            }
        }

        return ans;

    }
};