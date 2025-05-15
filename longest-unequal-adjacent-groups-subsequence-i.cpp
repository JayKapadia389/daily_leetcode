class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {

        bool curr = groups[0];
        vector<string> ans;

        ans.push_back(words[0]);

        for (int i = 1; i < words.size(); ++i) {
            if (groups[i] != curr) {
                ans.push_back(words[i]);
                curr = !curr;
            }
        }

        return ans;

    }
};