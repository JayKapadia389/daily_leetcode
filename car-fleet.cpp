class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        priority_queue<pair<int , int>> q ;

        for(int i = 0 ; i < position.size() ; i++){
            q.push({position[i] , speed[i]}) ;
        }

        int f=1 ;

        float t = static_cast<float>(target - (q.top()).first) / (q.top()).second ; 
        q.pop() ;

        while(!q.empty()){

            int pos = q.top().first ;
            int spd = q.top().second ;

            q.pop() ;

            if((static_cast<float>(target - pos)/spd) > t){
                f++ ;
                t = (static_cast<float>(target - pos)/spd) ;
            }


        }

        return f ;
        
    }
};