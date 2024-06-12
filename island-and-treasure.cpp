class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size() ;
        int n = grid[0].size() ;

        queue<pair<int,int>> q ; 

        for(int i =0 ; i< m ; i++){
            for(int j =0 ; j< n ;j++){

                if(grid[i][j] == 0){
                    q.push({i,j}) ;
                }
            }
        }

        vector<vector<int>> dir ={
            {-1 ,0},
            {0 ,1},
            {1 ,0},
            {0 ,-1},
        } ;

        int INF = INT_MAX ;

        while(!q.empty()){

            pair<int,int> p = q.front() ;

            q.pop() ;

            for(int i =0  ;i < 4 ; i++){

                int newX = p.first+dir[i][0] ;
                int newY = p.second+dir[i][1] ;

                if(grid[newX][newY] == INF){
                    grid[newX][newY] == (grid[p.first][p.second] + 1) ;
                    q.push({newX , newY}) ;
                }

            }

        }

        return ;
        
    }
};
