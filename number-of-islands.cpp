class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        queue<pair<int, int>> q ;
        int m = grid.size() ;
        int n = grid[0].size() ;
        int c = 0 ;

        vector<vector<int>> dir = {
            {-1 ,0} ,
            {0 ,1} ,
            {1 ,0} ,
            {0 ,-1} 
        } ;

        vector<vector<int>> bm(m , vector<int>(n)) ;

        for(int i =0 ; i< m; i++){
            for(int j = 0 ; j < n; j++){

                if(grid[i][j] == '1' && bm[i][j] == 0){

                    q.push({i,j}) ;
                    bm[i][j] = 1 ;

                    while(!q.empty()){

                        pair<int, int> p = q.front() ;
                        q.pop() ;

                        // bm[p.first][p.second] = 1 ;

                        for(int i = 0 ; i < 4 ; i++){

                            int newX = p.first+dir[i][0] ;
                            int newY = p.second+dir[i][1] ;
                            if(
                                (newX >= 0 && newX < m ) && 
                                (newY >= 0  && newY < n )
                            && 
                            (grid[newX][newY] == '1' && bm[newX][newY] == 0)){

                                q.push({newX , newY }) ;
                                bm[newX][newY] = 1 ;

                                

                            }
                        }

                    }

                    c++ ;

                }

            }
        }

        return c ;

        
    }
};