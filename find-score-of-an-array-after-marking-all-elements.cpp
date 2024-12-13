class Solution {
public:
    long long findScore(vector<int>& nums) {

        int n = nums.size(), idx;
        long long score = 0;
        vector<int> marked(n, 0);
        vector<pair<int, int >> pairsV;

        for (int i = 0; i < n; i++)
            pairsV.push_back({ nums[i] , i });

        sort(pairsV.begin(), pairsV.end());

        for (int i = 0; i < n; i++) {

            if (!marked[pairsV[i].second]) {
                score += pairsV[i].first;

                idx = pairsV[i].second;
                marked[idx] = 1;
                if (idx - 1 >= 0) {
                    marked[idx - 1] = 1;
                }
                if (idx + 1 < n) {
                    marked[idx + 1] = 1;
                }
            }

        }

        return score;

    }
};