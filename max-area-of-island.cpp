class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int m = grid.size() ;
        int n = grid[0].size() ;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(m , vector<int>(n)) ;
        int ans = 0 ;
        int size =0 ;

        vector<vector<int>> dir = {
            {-1,0},
            {0,1},
            {1,0},
            {0,-1},
        } ;

        for(int i=0 ; i< m ; i++){
            for(int j=0 ; j < n ; j++){

                if(grid[i][j] == 1 && visited[i][j] == 0){

                    size = 0;

                    q.push({i,j});
                    visited[i][j] = 1 ;

                    size++ ;

                    while(!q.empty()){
                        pair<int,int> p = q.front() ;
                        q.pop() ;

                        for(int x =0 ; x < 4 ; x++){

                            int newX = p.first+dir[x][0] ;
                            int newY = p.second+dir[x][1];

                            if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1 && visited[newX][newY]== 0){
                                q.push({newX , newY}) ;
                                visited[newX][newY] = 1;
                                size++ ;
                            }

                        }


                    }

                    ans = max(ans , size) ;

                }

            }
        }

        return ans ;
         
    }
};