class Solution {
public:
    int minimumLength(string s) {

        map<char, int> freq;

        for (auto c : s)
            ++freq[c];

        int c = 0;

        for (auto i : freq) {
            if (i.second % 2 == 0)
                c += 2;
            else
                c += 1;
        }

        return c;

    }
};