class Solution {
private:
int OFFSET = 1;

public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<bool> dp2(n + 2, false);
        vector<bool> dp1(n + 2, false);
        dp2[0 + OFFSET] = true;

        for(int j = n - 1; j >= 0; --j) {
            for(int i = 0; i < n; ++i) {
                dp1[OFFSET + i] = false;

                if(s[j] == '*' || s[j] == '(') {
                    dp1[OFFSET + i] = dp1[OFFSET + i] || dp2[OFFSET + i + 1];
                }

                if(s[j] == '*') {
                    dp1[OFFSET + i] = dp1[OFFSET + i] || dp2[OFFSET + i];
                }

                if(s[j] == '*' || s[j] == ')') {
                    dp1[OFFSET + i] = dp1[OFFSET + i] || dp2[OFFSET + i - 1];
                }
            }

            swap(dp1, dp2);
        }

        return dp2[OFFSET + 0];
    }
};