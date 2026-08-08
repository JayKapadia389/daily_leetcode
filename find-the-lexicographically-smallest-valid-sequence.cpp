class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> arr(n + 1, 0);
        vector<int> ans(m, -1);
        bool spell_available = 1;

        for(int i = n - 1, j = m - 1; i >= 0; --i){
            if(j == -1 || word1[i] != word2[j]) {
                arr[i] = arr[i + 1];
            }
            else{
                arr[i] = arr[i + 1] + 1;
                --j;
            }
        }

        int j = 0;
        for(int i = 0; i < n && j < m; ++i) {
            if(word1[i] == word2[j]){
                ans[j] = i;
                ++j;
            }
            else if(spell_available && arr[i + 1] >= (m - j - 1)) {
                ans[j] = i;
                ++j;
                spell_available = false;
            }
        }

        return (j == m)? ans : vector<int>();
    }
};