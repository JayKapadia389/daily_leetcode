class Solution{
public:

    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited(V, 0) ; 
        queue<pair<int,int>> q;

        for(int i = 0 ; i < V ; ++i){
            if(!visited[i]){

                q.push({i , -1});
                visited[i] = 1 ; 

                while(!q.empty()){

                    auto p = q.front();
                    q.pop() ; 

                    for(auto elem: adj[p.first]){
                        if(!visited[elem]){
                            visited[elem] = 1 ; 
                            q.push({elem , p.first}) ;
                        }
                        else if(elem != p.second){

                            cout << elem << " " << p.second ; 
                            return true ; 
                        }
                    }

                }

            }
        }

        return false ;

    }
};