class Solution {
public:

    void recc(int& ans, map<char, int>& freq) {

        for (auto& i : freq) {
            if (i.second != 0) {
                ++ans;
                --(i.second);
                recc(ans, freq);
                ++(i.second);
            }
        }

        return;
    }

    int numTilePossibilities(string tiles) {

        int ans = 0;
        map<char, int> m;

        for (auto c : tiles) {
            ++m[c];
        }

        recc(ans, m);

        return ans;

    }
};