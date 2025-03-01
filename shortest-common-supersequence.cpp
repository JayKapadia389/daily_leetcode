class Solution {
public:

    string LCS(string str1, string str2) {
        int len1 = str1.length() + 1;
        int len2 = str2.length() + 1;

        vector<vector<int>> grid(len1, vector<int>(len2, 0));

        for (int i = 1; i < len1; ++i) {
            for (int j = 1; j < len2; ++j) {
                if (str1[i - 1] == str2[j - 1]) {
                    grid[i][j] = grid[i - 1][j - 1] + 1;
                }
                else {
                    grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }

        string ans = "";

        int i = len1 - 1;
        int j = len2 - 1;

        while (i > 0 && j > 0) {
            if (grid[i][j] == grid[i][j - 1]) {
                j -= 1;
            }
            else if (grid[i][j] == grid[i - 1][j]) {
                i -= 1;
            }
            else {
                ans = str1[i - 1] + ans;
                i -= 1;
                j -= 1;
            }
        }
        return ans;
    }

    vector<string> tokenize(string str2, string lcs) {
        string temp = "";
        int iter = 0, i;
        int len2 = str2.length(), lcsLen = lcs.length();
        vector<string> ans;

        for (i = 0; i < len2; ++i) {
            if (iter < lcsLen && lcs[iter] == str2[i]) {
                ans.push_back(temp);
                temp = "";
                ++iter;
                if (iter == lcsLen) {
                    break;
                }
            }
            else {
                temp += str2[i];
            }
        }

        ans.push_back(temp + str2.substr(i + 1));

        return ans;
    }

    void construct(string& ans, vector<string>& tokens, string& lcs) {
        int lcsIter = 0, ansIter = 0, tokensIter = 0;

        while (lcsIter < lcs.length()) {
            if (lcs[lcsIter] == ans[ansIter]) {
                ans.insert(ansIter, tokens[tokensIter]); 
                ansIter += tokens[tokensIter].length();   
                ++tokensIter;
                ++lcsIter;
            }
            ++ansIter;
        }

        ans += tokens[tokensIter];
    }

    string shortestCommonSupersequence(string str1, string str2) {
        string lcs = LCS(str1, str2);
        string ans = str1;
        vector<string> tokens = tokenize(str2, lcs);
        construct(ans, tokens, lcs);
        return ans;
    }
};
