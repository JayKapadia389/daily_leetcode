class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> missing;

        for(int i = 0, j = lower; j <= upper; ++j){
            while(i < n && nums[i] < j){
                ++i;
            }

            if(i >= n || nums[i] > j){
                missing.push_back(j);
            }

            if(i < n && nums[i] == j){
                ++i;
            }    
        }

        vector<vector<int>> intervals;

        if(missing.size() == 0){
            return intervals;
        }

        vector<int> interval(2);
        int first = missing[0];
        interval[0] = first;
        int m =  missing.size();
        
        for(int i = 0; i < m; ++i){
            if(i + 1 == m || missing[i + 1] != missing[i] + 1){
                interval[1] = missing[i];
                intervals.push_back(interval);

                if(i + 1 != m){
                    interval[0] = missing[i + 1];
                }
            }
        }

        return intervals;
    }
};