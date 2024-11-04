class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        // map<int , int > idx ;
        int n = intervals.size() ; 
        int m = queries.size() ; 

        vector<pair<int , int>> queries_idx ; 

        for(int i = 0 ; i < m ; i++){

            queries_idx.push_back({queries[i] , i}) ;

        } 

        sort(intervals.begin() , intervals.end()) ; 
        sort(queries_idx.begin() , queries_idx.end()) ; 

        priority_queue<pair<int , int> , vector<pair<int , int >> , greater<> > q; 
        int j = 0 , query;
        vector<int> ans(m) ;

        for(int i = 0 ; i < m ; i++){

            query = queries_idx[i].first ;

            while(j < n && intervals[j][0] <= query){

                q.push({(intervals[j][1] - intervals[j][0] + 1) , intervals[j][1]}) ;

                ++j ;

            }

            while(!q.empty() && (q.top()).second < query){
                q.pop() ; 
            }

            if(q.empty()){
                ans[queries_idx[i].second] = -1 ;
                cout << "-1 "  ;

            }
            else{
                ans[queries_idx[i].second] = q.top().first ;
                cout << q.top().second << " ";

            }

        }

        return ans ;
    }
};