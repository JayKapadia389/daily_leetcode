class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        map<int , bool> distinct ;

        for(auto i : prerequisites){
            distinct[i[0]] = 1 ;
            distinct[i[1]] = 1 ;
        }

        for(auto i : distinct){
            cout << i.first << " ";
        }
        cout << endl ;

        map<int,bool> noPrereq = distinct ;

        for(auto i : prerequisites){
            noPrereq[i[0]] = 0 ;
        }

        vector<int> noPrereqVec ;

         for(auto i : noPrereq){
            if(i.second){
                noPrereqVec.push_back(i.first) ;
            }
        }
        
        for(auto i : noPrereqVec){
            cout << i ;
        }

        int num = 0 ;

        for(auto i : noPrereqVec){

            queue<int> q ;

            q.push(i) ;
            num++ ;

            while(!q.empty()){

              int curr = q.pop() ;

              for(auto j : prerequisites)  

            }


        }

        
    }
};