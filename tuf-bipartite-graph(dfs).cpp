class Solution{
private:
    vector<int> colors_; 

    bool dfs(int i, int color, vector<int>& adj[]){
        colors_[i] = color;

        for(int n : adj[i]){
            if(colors_[n] != -1){
                if(colors_[n] == color){
                    return false;
                }
            }
            else{
                if(!dfs(n,!color)){
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])  {
        colors_.clear();
        colors_ = vector<int>(V, -1);

        for(int i = 0 ; i < V; ++i){
            if(colors[i] == -1 && !dfs(i,0,adj)){
                return false;
            }
        }
        return true;
    }
};
