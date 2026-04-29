int MAX_BRICKS = 1e4;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int divisor) {
        int m = grid.size(), n = grid[0].size(), len = m*n;
        vector<int> flattened;

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                flattened.push_back(grid[i][j]);
            }
        }

        sort(flattened.begin(), flattened.end());

        int base_remainder = flattened[0] % divisor;
        int x = 0;
        int y = 0; 

        for(int i = 0; i < len; ++i){
            int quotient = flattened[i] / divisor;
            int remainder = flattened[i] % divisor;

            if(remainder != base_remainder){
                return -1;
            }
            flattened[i] = quotient;
            y += quotient;
        }

        unordered_map<int, int> freq_greater_or_equal_to;
        int suffix = 0;

        for(int i = MAX_BRICKS, j = len - 1; i >= 0;){
            if(j >= 0 && i == flattened[j]){
                ++suffix;
                --j;
            }
            else{
                --i;
            }
            freq_greater_or_equal_to[i] = suffix;
        }

        int ans = x + y;
        for(int i = 1; i <= MAX_BRICKS; ++i){
            x += (len - freq_greater_or_equal_to[i]);
            y -= (freq_greater_or_equal_to[i]);
            ans = min(ans, x + y);
        }

        return ans;
    }
};