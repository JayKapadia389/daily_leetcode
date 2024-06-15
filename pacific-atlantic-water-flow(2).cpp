class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        vector<vector<int>> ans ; 

        int m = heights.size() ;
        int n = heights[0].size() ;

        vector<vector<int>> dir = {
            {-1 ,0} , 
            {0 ,1} , 
            {1 ,0} , 
            {0 ,-1} , 
        };

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j< n ; j++){

                bool atl = false , pac = false ;

                queue<pair<int,int>> q ;

                q.push({i , j}) ;
                vector<vector<bool>> vis(m , vector<bool>(n , false))  ; 

                while(!((atl && pac) || q.empty())){

                    pair<int , int> curr = q.front() ;
                    int currFirst = curr.first ;
                    int currSecond = curr.second ;
                    q.pop() ;

                    for(int x = 0 ; x < 4 ; x++){
                        if(currFirst+dir[x][0] < 0 || currSecond+dir[x][1] < 0){
                            pac = true ;
                        }
                        if(currFirst+dir[x][0] == m  || currSecond+dir[x][1] == n){
                            atl = true ;
                        }
                    }

                    for(int x = 0 ; x < 4 ; x++){
                        int newX = currFirst+dir[x][0];
                        int newY = currSecond+dir[x][1];

                        if(newX >= 0 && newX < m && newY >=0 && newY < n && !vis[newX][newY] && 
                        heights[newX][newY] <= heights[currFirst][currSecond]){

                            vis[newX][newY] = 1 ;
                            
                            q.push({newX , newY}) ;

                        }
                    }

                }

                if(pac && atl){
                    vector<int> temp = {i , j} ;
                    ans.push_back(temp) ;
                }
            }
        }

        return ans ;
        
    }
};
