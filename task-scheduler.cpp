class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        map<char , int> freq ;

        for(int i = 0 ; i < tasks.size() ; i++){

            freq[tasks[i]]++ ;

        } 

        priority_queue<int> pq ;

        for(auto i : freq){

            pq.push(i.second) ;

        }

        int time = 0 ;

        queue<pair<int , int >> q ;

        while(!pq.empty() || !q.empty()){

            cout << "1" <<endl ;

            if(!pq.empty()){
                int x = pq.top() ;
                pq.pop() ;

                if(x != 1){
                    q.push( { --x , time+ n + 1}) ;
                }
            }

            time++ ;

            if(!q.empty() && q.front().second == time){
                pq.push(q.front().first) ;
                q.pop() ;
            }

        }

            return time ;    
        
    }
};