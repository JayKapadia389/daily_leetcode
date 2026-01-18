class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int l = 1, m = grid.size(), n = grid[0].size();

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                for(int k = l+1; (i+k) <= m && (j+k) <= n; ++k){
                    bool same = 1;
                    int what = 0;

                    // horizontal 
                    for(int p = 0; p < k; ++p){
                        if(!same) break;
                        int curr = 0;
                        for(int q = 0; q < k; ++q){
                            curr += grid[i+p][j+q];
                        }
                        if(what == 0){
                            what = curr;
                        }
                        else{
                            if(curr != what){
                                same = 0;
                                break;
                            }
                        }
                    }

                    // verticle
                    if(!same) continue;
                    for(int q = 0; q < k; ++q){
                        if(!same) break;
                        int curr = 0;
                        for(int p = 0; p < k; ++p){
                            curr += grid[i+p][j+q];
                        }
                        
                        if(curr != what){
                            same = 0;
                            break;
                        }
                    }
                    
                    // l-r diagonal 
                    if(!same) continue;
                    int curr = 0;
                    for(int z = 0; z < k; ++z){
                        curr += grid[i+k-z-1][j+z];
                    }
                    if(curr != what) same = 0;

                    // r-l d
                    if(!same) continue;
                    curr = 0;
                    for(int z = 0; z < k; ++z){
                        curr += grid[i+z][j+z];
                    }
                    if(curr != what) same = 0;

                    if(same) l = max(l, k);
                }
            }
        }

        return l;
    }
};