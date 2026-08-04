class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> missing;

        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; ++i){
            int prev = nums[i - 1];
            int curr = nums[i];
            for(int j = prev + 1; j < curr; ++j){
                missing.push_back(j);
            }
        }

        return missing;
    }
};