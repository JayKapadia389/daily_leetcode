class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0, n = s.length();

        for(int i = 0; i < n; ++i) {
            int temp = (i + 1) * (26 - (s[i] - 'a'));
            sum += temp;
        }

        return sum;
    }
};