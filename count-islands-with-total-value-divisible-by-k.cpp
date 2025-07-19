class Solution {
public:

    vector<vector<int>> dir;
    int m, n;
    
    Solution(){
        dir = {
            {-1,0},
            {0,1},
            {1,0},
            {0,-1}
        };
    }

    void dfs(int& i, int& j, long long& totalValue, vector<vector<bool>>& visited, vector<vector<int>>& grid){

        visited[i][j] = 1;
        totalValue+=grid[i][j];

        for(int k = 0; k < 4; ++k){

            int x = i+dir[k][0];
            int y = j+dir[k][1];
            
            if(x>=0 && x<m && y>=0 && y<n && grid[x][y] && !visited[x][y]){
                dfs(x,y,totalValue,visited,grid);
            }
        }

        return;
        
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {

        m = grid.size() ;
        n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, 0)) ; 

        int cnt = 0 ; 
        
        for(int i = 0; i < m; ++i){
            for(int j = 0 ; j < n; ++j){
                if(grid[i][j] && !visited[i][j]){

                    // cout << i << ", " << j << endl ; 
                    long long totalValue = 0;
                    // cout <<endl<< "called: " << i << ", " << j << endl ;  
                    dfs(i,j, totalValue, visited, grid);

                    if(totalValue%k == 0){
                        // cout << "div: "<< i << ", "<<j << endl ;  
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }
};