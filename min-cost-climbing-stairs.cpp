class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size() ; 
        vector<int> minCost(n+1 , 0) ;

        for(int i = 2 ; i <= n ; ++i){
            minCost[i] = min( cost[i-2] + minCost[i-2] 
                            , cost[i-1] + minCost[i-1]) ; 
        }

        return minCost[n] ; 
        
    }
};