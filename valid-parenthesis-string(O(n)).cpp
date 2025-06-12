class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            } else if (ch == ')') {
                low = max(low - 1, 0);
                high--;
            } else { // '*'
                low = max(low - 1, 0);
                high++;
            }
            if (high < 0) return false;
        }
        return low == 0;
    }
};
