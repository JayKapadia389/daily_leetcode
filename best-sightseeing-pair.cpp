class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {

        int ans = INT_MIN;
        int viplusi_max = values[0] + 0;

        for (int j = 1; j < values.size(); j++) {

            ans = max(ans, viplusi_max + values[j] - j);

            viplusi_max = max(viplusi_max, values[j] + j);
        }

        return ans;

    }
};