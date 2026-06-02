class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int ans = INT_MAX, n = landStartTime.size(), m = waterStartTime.size();

        // land first approach
        int land_first_min_time = INT_MAX;
        for(int i = 0; i < n; ++i){
            land_first_min_time = min(land_first_min_time, landStartTime[i] + landDuration[i]);
        }

        for(int j = 0; j < m; ++j){
            int time = land_first_min_time + waterDuration[j] + max(0, waterStartTime[j] - land_first_min_time);
            ans = min(ans, time);
        }

        // water first approach
        int water_first_min_time = INT_MAX;
        for(int j = 0; j < m; ++j){
            water_first_min_time = min(water_first_min_time, waterStartTime[j] + waterDuration[j]);
        }

        for(int i = 0; i < n; ++i){
            int time = water_first_min_time + landDuration[i] + max(0, landStartTime[i] - water_first_min_time);
            ans = min(ans, time);
        }

        return ans;
    }
};