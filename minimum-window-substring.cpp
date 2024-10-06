class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";
        
        unordered_map<char, int> constFreq;
        for (char c : t) {
            constFreq[c]++;
        }

        unordered_map<char, int> varFreq;
        int required = constFreq.size(); 
        int formed = 0; 

        int left = 0, right = 0;
        int minLen = INT_MAX;
        int start = 0;

        while (right < s.size()) {
            char c = s[right];
            varFreq[c]++;

            if (constFreq.count(c) && varFreq[c] == constFreq[c]) {
                formed++;
            }

            while (left <= right && formed == required) {
                char startChar = s[left];

                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                varFreq[startChar]--;
                if (constFreq.count(startChar) && varFreq[startChar] < constFreq[startChar]) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};
