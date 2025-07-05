class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {

        vector<vector<long long>> ans(m , vector<long long>(n,0)) ; 
        ans[0][0] = 1 ; 

        for(int j = 1 ; j < n ; ++j){
               ans[0][j] = waitCost[0][j] + (ans[0][j-1] + 1*(j+1)) ; 
        }

        for(int i = 1 ; i < m ; ++i){
                ans[i][0] = waitCost[i][0] + (ans[i-1][0] + (i+1)*1) ; 
        }

        for(int i = 1 ; i < m ;++i){
            for(int j = 1 ; j < n ; ++j){
                ans[i][j] = waitCost[i][j] + ( (i+1)*(j+1) + min(ans[i-1][j] , ans[i][j-1]));
            }
        }

        return ans[m-1][n-1] - waitCost[m-1][n-1] ; 
    }
};