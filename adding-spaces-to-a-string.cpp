class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

        int m = spaces.size(), n = s.length();

        for (int i = 0; i < m; i++) {
            spaces[i] += i;
        }

        int c1 = 0, c2 = 0;
        string ans = "";

        for (int i = 0; i < n + m; i++) {

            if (c1 < m && i == spaces[c1]) {
                ans += " ";
                ++c1;
            }
            else {
                ans += s[c2];
                ++c2;
            }

        }

        return ans;

    }
};