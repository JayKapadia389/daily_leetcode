class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> v;

        for(int i = 0; i < n; ++i){
            int cnt = 0;
            for(int j = n-1; j >= 0; --j){
                if(grid[i][j] != 0){
                    break;
                }
                ++cnt;
            }
            v.push_back(cnt);
        }

        int op = 0;
        for(int i = 0; i < n; ++i){
            int req = n - i - 1;
            int j = i;
            for(; j < n; ++j){
                if(v[j] >= req){
                    break;
                }
            }

            if(j == n){
                return -1;
            }

            for(int k = j; k > i; --k){
                swap(v[k], v[k-1]);
                ++op;
            }
        }

        return op;
    }
};