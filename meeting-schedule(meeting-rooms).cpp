/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {

        vector<pair<int , int>> events ;

        for(auto i : intervals){

            events.push_back({i.start , 1});
            events.push_back({i.end , -1});

        }

        sort(events.begin() , events.end()) ;

        int presum = 0 ;

        for(auto i : events){

            presum+= i.second ;

            if(presum > 1){
                return false ;
            }

        }

        return true ;
        
    }
};

//0:03:15