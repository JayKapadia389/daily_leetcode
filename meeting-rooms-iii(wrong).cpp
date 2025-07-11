class Solution {
public:
    struct CustomPairCompare {
        bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first; 
            }
            return a.second > b.second; // check this
        }
    };

    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        //check edge case for this.
        int mx_meeting_room = INT_MAX , mx_meeting_cnt = 0 ; 
        map<int , int> freq ; 

        priority_queue<pair<int , int> , vector<pair<int , int>> , CustomPairCompare> pq ; 
        for(int i = 0 ; i < n ; ++i){
            pq.push({0,i}) ; 
        }

        sort(meetings.begin() , meetings.end()) ; 

        for(auto meeting : meetings){

            auto p = pq.top() ;
            pq.pop();

            //freq ++ , reset answer
            ++freq[p.second] ; 
            if(freq[p.second] == mx_meeting_cnt){
                mx_meeting_room = min(mx_meeting_room , p.second) ; 
            }
            else{
                if(freq[p.second] > mx_meeting_cnt){
                    mx_meeting_cnt = freq[p.second] ; 
                    mx_meeting_room = p.second ; 
                }
            }

            p.first = max(p.first , meeting[0]) +  meeting[1] - meeting[0] ; 
        }

        return mx_meeting_room ; 

    }
};