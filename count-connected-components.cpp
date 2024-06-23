class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        int m = edges.size() ;
        vector<bool> visited(n , 0) ;
        queue<int> q ;

        int c = 0  ;

        for(int i = 0 ; i < n ; i++){

            if(!visited[i]){
                q.push(i) ;
                visited[i] = 1;

                c++ ;

                while(!q.empty()){

                    int curr = q.front() ;
                    q.pop() ;

                    for(int j = 0 ; j < m ; j++ ){

                        if(edges[j][0] == curr || edges[j][1] == curr ){
                            int x = (edges[j][0] == curr) ? edges[j][1] : edges[j][0] ;

                            if(visited[x] == 0){
                                q.push(x) ;
                                visited[x] = 1 ;
                            }
                        }

                    }

                }
            }

        }

        return c ;

    }
};
