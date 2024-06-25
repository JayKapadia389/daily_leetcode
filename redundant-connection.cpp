class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size() ;

        vector<int> rank(n+1 , 1) ;
        vector<int> par(n+1) ;
        vector<int> ans(2) ;

        for(int i = 1 ; i <= n ; i++){
            par[i] = i ;
        }

        for(int i = 0 ; i < n ; i++){

            int par1 = par[edges[i][0]] ;
            int par2 = par[edges[i][1]];


            if( par1 == par2 ){
                 ans[0] = edges[i][0] ;
                 ans[1] = edges[i][1] ; 
                 return ans ;
           }

           if(rank[par1] < rank[par2]){
            int temp = par1 ;
            par1 = par2 ;
            par2 = temp ;
           }

           for(int i = 1 ; i <= n ; i++){
            if(par[i] == par2){
                par[i] = par1 ;
            }
           }

           rank[par1] = rank[par1] + rank[par2] ;


        }

        return ans ;
    }
};