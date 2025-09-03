class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        vector<vector<int>> v(51 , vector<int>(51 , 0));

        for(auto point : points){
            v[point[0]][point[1]] = 1;
        }

        for(int i = 0; i <= 50; ++i){
            int recent = 51;
            for(int j = 50; j >= 0; --j){
                if(v[i][j] == 1){
                    recent = j;
                }
                v[i][j] = recent;
            }
        }

        int ans = 0;

        for(auto point : points){
            int base_i = point[0];
            int base_j = point[1];
            int recent = 51;

            if(base_j != 50 && v[base_i][base_j + 1] < recent){
                recent = v[base_i][base_j + 1];
                ++ans;
            }

            for(int i = base_i - 1; i >= 0; --i){
                if(v[i][base_j] < recent){
                    recent = v[i][base_j];
                    ++ans;
                }
            }
        }

        return ans;
    }
};