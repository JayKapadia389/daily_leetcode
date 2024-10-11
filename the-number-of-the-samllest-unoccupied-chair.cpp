class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {

        int n = times.size() ;

        vector<pair<int , int >> arrivaltime(n) ;
        vector<pair<int , int >> leavingtime(n) ;

        for(int i = 0 ; i < n ; i++){

            arrivaltime[i] = {times[i][0] , i } ;
            leavingtime[i] = {times[i][1] , i } ;

        }

        sort(arrivaltime.begin() , arrivaltime.end()) ;
        sort(leavingtime.begin() , leavingtime.end()) ;

        int x = 0 , y = 0;
        int t = 1 ;
        int l = 0 ; 
        vector<bool> occ(n , 0) ;
        map<int,int> m ;

        while(true){

            //handle departure

            while(leavingtime[y].first == t){   
                occ[m[leavingtime[y].second]] = 0;
                l = min(l , m[leavingtime[y].second] ) ;

                y++ ;
            }

            //handle arrival 

            if(arrivaltime[x].first == t){

            //check andcreturn
                if(targetFriend == arrivaltime[x].second ){
                    return l ;
                }

                occ[l] = 1 ;
                m[arrivaltime[x].second] = l ;
                while(occ[l] != 0){
                    l++ ;
                }

                x++ ;

            }

            //
            t++ ; 

        }
        
    }
};