class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> prev_two(n+1, vector<int>(2, -1));

        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); ++i){
            int num = nums[i];

            if(prev_two[num][0] != -1){
                ans = min(ans, 2 * (i - prev_two[num][0]));
            }

            prev_two[num][0] = prev_two[num][1];
            prev_two[num][1] = i;
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};