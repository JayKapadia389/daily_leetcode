class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> pairs;

        for(int i = 0; i < n; ++i) {
            pairs.push_back({nums[i], i});
        }

        sort(pairs.begin(), pairs.end());

        vector<int> idxs;
        for(int i = 0; i < n; ++i) {
            idxs.push_back(pairs[i].second);

            if(i + 1 >= n || (pairs[i + 1].first - pairs[i].first) > limit){
                int comp_size = idxs.size();
                int begin = i - comp_size + 1;

                sort(idxs.begin(), idxs. end());

                for(int j = 0; j < comp_size; ++j){
                    nums[idxs[j]] = pairs[begin + j].first;
                }

                idxs.clear();
            }
        }

        return nums;
    }
};