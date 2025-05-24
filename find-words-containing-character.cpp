class Solution {
public:

    bool has(string& word, char& x) {
        for (auto ch : word) {
            if (ch == x) {
                return true;
            }
        }
        return false;
    }

    vector<int> findWordsContaining(vector<string>& words, char x) {

        vector<int> indices;
        int n = words.size();

        for (int i = 0; i < n; ++i) {
            if (has(words[i], x))
                indices.push_back(i);
        }

        return indices;

    }
};