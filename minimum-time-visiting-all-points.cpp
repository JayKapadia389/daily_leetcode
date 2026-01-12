class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int min_time = 0;

        for(int i = 0; i < points.size()-1; ++i){
            int x_dis = abs(points[i][0] - points[i+1][0]);
            int y_dis = abs(points[i][1] - points[i+1][1]);
            min_time += max(x_dis, y_dis);
        }

        return min_time;
    }
};