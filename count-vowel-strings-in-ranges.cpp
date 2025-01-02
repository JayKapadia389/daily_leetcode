class Solution {
public:

    bool isValid(string word) {
        char f = word[0], l = word[word.length() - 1];

        if ((f == 'a' || f == 'e' || f == 'i' || f == 'o' || f == 'u') &&
            (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u')) {
            return true;
        }
        return false;
    }

    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {

        int n = words.size(), presum = 0, m = queries.size();

        vector<int> presumVec(n, 0);
        vector<int> ans(m, 0);

        for (int i = 0; i < n; i++) {
            if (isValid(words[i]))
                ++presum;

            presumVec[i] = presum;

        }

        int l, r;

        for (int i = 0; i < m; i++) {

            l = queries[i][0];
            r = queries[i][1];

            if (l == 0) {
                ans[i] = presumVec[r];
            }
            else {
                ans[i] = presumVec[r] - presumVec[l - 1];
            }
        }

        return ans;

    }
};