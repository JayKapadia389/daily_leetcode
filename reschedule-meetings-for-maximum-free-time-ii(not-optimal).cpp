class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        
        int ans = 0 ; 
        map<int , int > gap_freq ; 
        vector<int> gaps ;
        int n = startTime.size();

        gaps.push_back(startTime[0] - 0) ; 
        ++gap_freq[startTime[0] - 0];
        for(int i = 0 ; i < n-1 ; ++i){
            gaps.push_back(startTime[i+1] - endTime[i]) ; 
            ++gap_freq[startTime[i+1] - endTime[i]];
        }
        gaps.push_back(eventTime - endTime[n-1]) ; 
        ++gap_freq[eventTime - endTime[n-1]];

        gap_freq[INT_MAX] = 0 ; 

        int prev = 0 ; 
        auto it = gap_freq.end() ; --it;  
        for(; it != gap_freq.begin() ; --it ){
            it->second += prev ; 
            prev = it->second ;  
        }

        //first
        it->second += prev ; 

        for(int i = 0 ; i < n ; ++i){

            int f = gaps[i], s = gaps[i+1]  ; 
            int interval = endTime[i] - startTime[i] ;

            int temp = f+s ; 

            //can we yeet the block?
            int c = 0 ;
            if(f >= interval){
                ++c ; 
            }
            if(s >= interval){
                ++c ; 
            }

            if(gap_freq.find(interval) != gap_freq.end()){
                if(gap_freq[interval] - c > 0){
                    temp += interval ; 
                    cout << temp ; 
                }
            }
            else{
                if((gap_freq.upper_bound(interval))->second - c > 0){
                    temp += interval ; 
                    cout << temp ; 
                }
            }
            ans = max(ans , temp) ; 
        }

        return ans ; 
    }
};