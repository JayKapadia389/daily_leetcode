class Solution {
private:
static bool comp(vector<int>& a, vector<int>& b) {
    if(a[0] != b[0]){
        return a[0] < b[0];
    }
    return a[1] > b[1];
}

public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int removed = 0;
        int mx_endpoint = -1;

        sort(intervals.begin(), intervals.end(), comp);

        for(int i = 0; i < n; ++i) {
            if(intervals[i][1] <= mx_endpoint) {
                ++removed;
            }
            mx_endpoint = max(mx_endpoint, intervals[i][1]);
        }

        return n - removed;
    }
};