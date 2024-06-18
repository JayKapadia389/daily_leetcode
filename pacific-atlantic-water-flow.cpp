class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size() ;
        int n = heights[0].size() ;

        vector<vector<int>> ans ;
        vector<vector<int>> pacific ;
        vector<vector<bool>> pacificVis(m , vector<bool>(n)) ;

        vector<vector<int>> atlantic ;
        vector<vector<bool>> atlanticVis(m , vector<bool>(n)) ;


        for(int i = 0 ; i < n ;i++){
            pacific.push_back({0,i});
            pacificVis[0][i] = 1 ;
        }
        for(int i = 1 ; i < m ; i++){
            pacific.push_back({i,0}) ;
            pacificVis[i][0] = 1 ;

        }

        for(int i = 0 ; i < n ;i++){
            atlantic.push_back({m-1,i});
            atlanticVis[m-1][i] = 1 ;

        }
        for(int i = 0 ; i < m-1 ; i++){
            atlantic.push_back({i,n-1}) ;
            atlanticVis[i][n-1] = 1 ;
        }

        vector<vector<int>> dir = {
            {-1 , 0} ,
            {0 , 1} ,
            {1 , 0} ,
            {0 , -1} ,

        };
        
        queue<pair<int,int>> q ;

        for(int i = 0 ; i< pacific.size() ; i++ ){
            q.push({pacific[i][0] , pacific[i][1]}) ;
        } 

        while(!q.empty()){

            pair<int,int> curr = q.front() ;
            q.pop() ;

            for(int i = 0 ; i< 4 ; i++){

                int newX = curr.first+dir[i][0] ;
                int newY = curr.second+dir[i][1] ;

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && pacificVis[newX][newY] == 0 && heights[newX][newY] >= heights[curr.first][curr.second]){
                    pacificVis[newX][newY] = 1;
                    q.push({newX , newY}) ;
                    pacific.push_back({newX , newY}) ; 
                }


            }

        }

        //atlantic

        for(int i = 0 ; i< atlantic.size() ; i++ ){
            q.push({atlantic[i][0] , atlantic[i][1]}) ;
        } 

        while(!q.empty()){

            pair<int,int> curr = q.front() ;
            q.pop() ;

            for(int i = 0 ; i< 4 ; i++){

                int newX = curr.first+dir[i][0] ;
                int newY = curr.second+dir[i][1] ;

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && atlanticVis[newX][newY] == 0 && heights[newX][newY] >= heights[curr.first][curr.second]){
                    atlanticVis[newX][newY] = 1;
                    q.push({newX , newY}) ;
                    atlantic.push_back({newX , newY}) ; 
                }


            }

        } 

        for(int i = 0 ; i < pacific.size() ; i++){
            for(int j = 0 ; j < atlantic.size() ; j++){
                if((pacific[i][0] == atlantic[j][0]) && (pacific[i][1] == atlantic[j][1])){
                    ans.push_back(pacific[i]) ;
                    break ;
                }
            }
        }

        return ans ;
        
    }
};