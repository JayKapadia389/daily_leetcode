class Solution {
public:

    int first , second ;
    vector<int> cycle ;

    void recc(vector<bool> &edgeVis_ , vector<bool>&visited_ ,stack<int> &st ,vector<vector<int>>& edges , int &n ,int curr ){

        for(int i = 0 ; i < n ; i++){
            if((edges[i][0] == curr || edges[i][1] == curr) && edgeVis[i] != 1 ){
                int x = (edges[i][0] == curr) ? edges[i][1] : edges[i][0] ;

                if(x == second){
                    //fill ds
                    while(!st.empty()){
                        cycle.push_back(st.top()) ;
                        st.pop() ;
                    }

                    return ;
                }
                edgeVis_[i] = 1 ;
                st.push(x) ;
                dfs(x) ;
                
            }
        }

        if(!st.empty())
        st.pop() ;

        return ;

    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size() ;
        vector<bool> edgeVis(n , 0) ;
        vector<bool> visited(n+1, 0) ;
        

        queue<int> q ;

        q.push(1) ;
        visited[1] = 1 ;
        bool found = 0 ;

        vector<bool> edgeVis_(n , 0) ;
        vector<bool> visited_(n+1, 0) ;
        stack<int> st ;

        while(!found && !q.empty()){
            int curr = q.front() ;
            q.pop() ;

            for(int i = 0 ; i< n ; i++){
                if((edges[i][0] == curr || edges[i][1] == curr) && edgeVis[i] != 1 ){
                    int x = (edges[i][0] == curr) ? edges[i][1] : edges[i][0] ;

                    if(visited[x]){

                        first = curr ;
                        second = x ;
                        found = 1;
                        edgeVis_[i] = 1; 
                        break ;

                    }
                    else{

                        edgeVis[i] = 1;
                        visited[x] = 1;
                        q.push(x) ;

                    }
                }
            }
        }

        st.push(first) ;

        recc(edgeVis_ , visited_ , st , edges , n , first) ;

        //


    }
};