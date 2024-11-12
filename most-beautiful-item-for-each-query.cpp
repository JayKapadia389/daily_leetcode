class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        int beautyMax = 0;

        int m = queries.size();
        int n = items.size();

        vector<pair<int, int>> queriesWithIndex;
        for (int i = 0; i < m; i++) {
            queriesWithIndex.push_back({ queries[i] , i });
        }

        sort(items.begin(), items.end());
        sort(queriesWithIndex.begin(), queriesWithIndex.end());

        int currQ, itemsIter = 0, maxV = 0;

        for (int i = 0; i < m; i++) {

            currQ = queriesWithIndex[i].first;

            while (itemsIter != n && items[itemsIter][0] <= currQ) {

                maxV = max(maxV, items[itemsIter][1]);

                ++itemsIter;

            }

            queries[queriesWithIndex[i].second] = maxV;

        }

        return queries;
    }
};