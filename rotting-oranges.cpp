class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q ;

        int n = grid[0].size() ;
        int m = grid.size() ;

        int c = -1 ;

        for(int i =0 ; i < m ;i++){
            for(int j =0 ; j < n ;j++){
                if(grid[i][j] == 2){
                    q.push({i,j}) ;
                }
            }
        }

        pair<int,int> null = {-1 , -1} ;

        q.push(null) ;

        vector<vector<int>> dir = {
            {-1 , 0} ,
            {0 , 1} ,
            {1 , 0} ,
            {0 , -1} ,
        } ;

        while(!q.empty()){

            pair<int,int> curr = q.front() ;

            cout << endl ;
            cout << curr.first << " " << curr.second << " -> " ;
            q.pop() ;
            cout << (curr == null) << endl;

            if(curr == null){
                c++ ;
                if(q.empty()){
                    break ;
                }
                else{
                    q.push(null) ;
                }
            }
            else{

                for(int i = 0 ; i < 4 ; i++){
                    int newX = curr.first+dir[i][0] ;
                    int newY = curr.second+dir[i][1] ;

                    if(newX >= 0 && newX < m &&
                       newY >= 0 && newY < n &&
                       grid[newX][newY] == 1){

                            grid[newX][newY] = 2 ;

                            q.push({newX , newY}) ;
                            cout << "(" << newX << " " << newY << ")"  ;

                       }

                }

            }

        }

        for(int i = 0 ; i < m ;i++){
            for(int j =0 ; j < n ;j++){
                if(grid[i][j] == 1){
                    return -1 ;
                }
            }
        }

        return c ;
        
    }
};