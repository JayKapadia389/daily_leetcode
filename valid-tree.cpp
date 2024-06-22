class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        int m = edges.size() ;

        for(int i = 0 ; i<m ; i++){
            if(edges[i][0] == edges[i][1]){
                return false ;
            }
        }

        queue<int> q ;
        vector<bool> visited(n) ;
        vector<bool> edgeVis(m) ;

        q.push(0) ;

        while(!q.empty()){

            int curr = q.front();
            q.pop() ;

            for(int i = 0 ; i < m ; i++){
                if(edgeVis[i] == 0 && (edges[i][0] == curr || edges[i][1] == curr)){
                    int x = (edges[i][0] == curr) ? edges[i][1] : edges[i][0] ;

                    if(visited[x]){
                        return false ;
                    }

                    visited[x] = 1 ;
                    q.push(x) ;
                    edgeVis[i] = 1 ;

                }
            }

        }

        for(int i = 0 ; i < m ; i++){
            if(edgeVis[i] == 0){
                return false ;
            }
        }

        return true ;

    }
};
