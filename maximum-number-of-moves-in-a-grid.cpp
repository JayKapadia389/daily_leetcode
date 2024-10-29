class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {

        int m = grid.size() ;
        int n = grid[0].size() ;
        int ans ;
        int newI, newJ ;

        vector<vector<int>> dp(m , vector<int>(n , 0)) ;

        for(int j = n-2 ; j >= 0 ; j--){

            for(int i = 0 ; i < m ; i++){

               ans = 0 ;

               for(int x = -1 ; x <= 1 ; x++ ){

                    newI = i + x ;
                    newJ = j+1 ; 

                    if(!(newI < 0 || newI >= m || newJ < 0 || newJ >= n )
                    && 
                    grid[i+x][j+1] > grid[i][j]){

                        ans = max(ans , dp[i+x][j+1]+1) ;

                    }

               }

               dp[i][j] = ans ;

            }

        }

        int finAns = 0 ;

        for(int i = 0  ; i < m ; i++){
            finAns = max(finAns , dp[i][0] ) ;
        }

        return finAns ;
        
    }
};