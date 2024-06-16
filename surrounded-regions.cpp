class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int m = board.size() ;
        int n = board[0].size() ;

        vector<vector<bool>> vis(m , vector<bool>(n , false)) ;

      vector<vector<int>> dir = {
            {-1,0},
            {0, 1},
            {1 ,0},
            {0,-1},
        };

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){

                if(board[i][j] != 'X' && vis[i][j] != 1){

                    vector<vector<int>> tempVec ;
                    queue<pair<int,int>> q ;
                    q.push({i,j}) ;
                    tempVec.push_back({i,j}) ;
                    vis[i][j] = 1 ;
                    bool onEdge = false ; 

                    while(!q.empty()){

                        pair<int,int> curr = q.front() ;
                        q.pop() ;

                        int newI = curr.first ;
                        int newJ = curr.second ;

                        for(int i = 0 ; i<4 ; i++){

                            int newX = newI+dir[i][0] ;
                            int newY = newJ+dir[i][1] ;

                            if(newX < 0 || newX == m || newY < 0 || newY == n){
                                onEdge = true ;
                            }
                            else{
                                if(board[newX][newY] == 'O' && vis[newX][newY] == 0){
                                    vis[newX][newY] = 1 ;
                                    tempVec.push_back({newX , newY}) ;
                                    q.push({newX,newY}) ;
                                }
                            }

                        }

                    }


                    if(!onEdge){
                        for(auto i : tempVec){
                            board[i[0]][i[1]] = 'X' ;
                        }
                    }


                }

            }
        }

        return ;
        
    }
};