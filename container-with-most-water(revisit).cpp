class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = INT_MIN, n = height.size();
        int i = 0, j = n-1;

        while(i < j){
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if(height[i] <= height[j]) ++i;
            else --j;
        }
        return ans;
    }
};