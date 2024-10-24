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
    int minMeetingRooms(vector<Interval>& intervals) {

        vector<pair<int , int>> events ;

        for(auto interval : intervals){

            events.push_back({interval.start , 1}) ;
            events.push_back({interval.end , -1}) ;

        }

        sort(events.begin() , events.end()) ;

        int preSum = 0 ;
        int ans = 0 ;

        for(auto e : events){
            
            preSum += e.second ;

            ans = max(ans , preSum) ;
        }

        return ans ;
        
    }
};
