class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {

        int n = queries.size();
        map<int, int> color;
        map<int, int> freq;
        int total = 0;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {

            int b = queries[i][0];
            int c = queries[i][1];

            if (color[b]) { //already colored
                if (color[b] == c) {
                    ans[i] = ans[i - 1];
                }
                else {
                    int pc = color[b];

                    --freq[pc];
                    if (freq[pc] == 0) {
                        --total;
                    }

                    ++freq[c];
                    if (freq[c] == 1) {
                        ++total;
                    }

                    color[b] = c;

                    ans[i] = total;
                }
            }
            else {
                color[b] = c;
                ++freq[c];
                if (freq[c] == 1) {
                    ++total;
                }
                ans[i] = total;
            }

        }

        return ans;

    }
};