class Solution {
public:

    int calc(vector<int> v){
        return (v[0]*v[0] + v[1]*v[1]); 
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        int s = points.size() ;

        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int , int>> > pq ;
        vector<vector<int>> ans ;

        for(int i = 0  ; i < s ; i++){

            pq.push({calc(points[i]) , i}) ;

        }

        for(int i = 0 ; i< k ; i++){

            pair<int ,int> p =  pq.top() ;
            pq.pop() ;

            ans.push_back(points[p.second]) ;

        }

        return ans ;
        
    }
};