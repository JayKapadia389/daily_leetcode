class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> intervalsWithEnd;
        for (vector<int> interval : intervals) {
            intervalsWithEnd.push_back({interval[0], 1});
            intervalsWithEnd.push_back({interval[1] + 1, -1});
        }

        sort(intervalsWithEnd.begin(), intervalsWithEnd.end());

        int concurrentIntervals = 0;
        int maxConcurrentIntervals = 0;
        for (auto p : intervalsWithEnd) {
            concurrentIntervals += p.second;
            maxConcurrentIntervals =
                max(maxConcurrentIntervals, concurrentIntervals);
        }

        return maxConcurrentIntervals;
    }
};