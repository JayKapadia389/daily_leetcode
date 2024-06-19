class Solution {
public:

     set<int> visited ;
    map<int,vector<int>> preMap ;

     bool dfs(int crs){

            if(visited.find(crs) != visited.end()){
                return false ;
            }

            if(preMap[crs].size() == 0){
                return true ;
            }

            visited.insert(crs) ;

            for(auto i : preMap[crs]){
                if(!dfs(i)){
                    return false ;
                } 
            }

            visited.erase(visited.find(crs)) ;

            preMap[crs] = {} ;

            return true ;

        }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        for(int i = 0 ; i < prerequisites.size() ; i++){

            preMap[prerequisites[i][0]].push_back(prerequisites[i][1]) ;

        }

        for(int i = 0 ; i< numCourses ; i++){
            if(!dfs(i))
            return false ;
        }

        return true ;
        
    }
};