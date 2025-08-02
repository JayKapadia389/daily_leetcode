class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {

        int mn1 = INT_MAX , mn2 = INT_MAX;

        for(int i = 0; i < landStartTime.size(); ++i){
            mn1 = min (mn1 , landStartTime[i]+landDuration[i]);
        }
        for(int i = 0; i < waterStartTime.size(); ++i){
            mn2 = min (mn2 , waterStartTime[i]+waterDuration[i]);
        }

        // land->water
        int x = INT_MAX;
        for(int i = 0; i < waterStartTime.size(); ++i){
            x = min(x , max(0 , waterStartTime[i] - mn1)+waterDuration[i]);
        }

        // water->land
        int y = INT_MAX;
        for(int i = 0; i < landStartTime.size(); ++i){
            y = min(y , max(0 , landStartTime[i] - mn2)+landDuration[i]);
        }

        return min(mn1+x , mn2+y);
        
    }
};