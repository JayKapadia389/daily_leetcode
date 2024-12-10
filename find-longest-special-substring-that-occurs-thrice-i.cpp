class Solution {
public:

    bool isSpecial(string ss) {
        char c = ss[0];

        for (auto i : ss) {
            if (i != c)
                return false;
        }

        return true;
    }

    int maximumLength(string s) {

        int n = s.length(), mx;
        int ans = -1;
        string ss;
        map<string, int> m;

        for (int i = 1; i <= n - 2; i++) {

            m.clear();

            for (int j = 0; j <= n - i; j++) {

                ss = s.substr(j, i);

                if (isSpecial(ss))
                    ++m[ss];

            }

            mx = 0;

            for (auto k : m) {
                mx = max(mx, k.second);
            }

            if (mx >= 3) {
                ans = i;
            }

        }

        return ans;

    }
};