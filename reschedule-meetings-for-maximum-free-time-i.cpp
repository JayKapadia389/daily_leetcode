class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        vector<int> gaps; 
        int n = startTime.size() ; 

        gaps.push_back(startTime[0] - 0) ; 

        for(int i = 0 ; i < n-1 ; ++i){
            gaps.push_back(startTime[i+1] - endTime[i]) ; 
        }
        gaps.push_back(eventTime - endTime[n-1]);

        int ans = 0 , temp = 0 ; 

        for(int i =0 ; i < k+1 ; ++i){
            temp += gaps[i] ; 
        }
        ans = temp ; 

        for(int i = 1; i < gaps.size() - k ; ++i){
            temp -= gaps[i-1] ; 
            temp += gaps[i+k] ;
            ans = max(ans, temp) ;  
        }

        return ans ; 

    }
};