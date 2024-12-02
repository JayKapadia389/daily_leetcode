class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {

        bool flag = 1;
        int ans = 1;
        int n = sentence.length();
        int len = searchWord.length();

        for (int i = 0; i < n; i++) {

            if (flag) {

                flag = 0;
                if ((i + len - 1) < n) {
                    if (sentence.substr(i, len) == searchWord) {
                        return ans;
                    }
                }
                else {
                    break;
                }

            }
            else if (sentence[i] == ' ') {
                flag = 1;
                ++ans;
            }

        }

        return -1;

    }
};