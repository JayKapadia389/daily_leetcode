class Solution {
private:
double area(int x1,int x2, int x3, int y1, int y2, int y3){
    return static_cast<double>(0.5) * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)); 
}

public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = INT_MIN;
        int n = points.size();

        for(int i = 0; i <= (n-3); ++i){
            for(int j = i + 1; j <= (n-2); ++j){
                for(int k = j+1; k <= (n-1); ++k){
                    ans = max(
                        ans, 
                        area(points[i][0], points[j][0], points[k][0], points[i][1], points[j][1], points[k][1])
                    );
                }
            }
        }
        return ans;
    }
};