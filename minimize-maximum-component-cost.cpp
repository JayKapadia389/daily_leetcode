class UnionFind {
    private:
    vector<int> leader;

    public:
    UnionFind(int n) : leader(n) {
        for(int i = 0 ; i < n ; ++i) { leader[i] = i; } 
    }
    
    int find(int i){
        return i == leader[i] ? i : (leader[i] = find(leader[i])) ; 
    }

    void merge(int i , int j){
        leader[i] = j ; 
    }
};

class Solution {
public:

    static bool comp(vector<int>& a , vector<int>& b){
        return  a[2] < b[2] ; 
    }
    
    int minCost(int n, vector<vector<int>>& edges, int k) {

        sort(edges.begin() , edges.end() , comp); //sort according to weights

        UnionFind union_find(n) ; 
        int comps = n ; // start with all components disconnected

        for(auto edge : edges){

            int left = edge[0] ; 
            int right = edge[1] ; 

            int sll = union_find.find(left); // supreme leader of left
            int slr = union_find.find(right); // supreme leader of right

            if(sll != slr){ // if both belong to different unions
                --comps ;  
                if(comps == k){
                    return edge[2] ; 
                }
                union_find.merge(sll , slr) ; 
            }
        }
        return 0 ; 
    }
};