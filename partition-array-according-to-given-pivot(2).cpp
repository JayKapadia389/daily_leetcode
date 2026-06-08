class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> greater_than;
        vector<int> ans;
        int cnt = 0;

        for(auto num : nums){
            if(num < pivot){
                ans.push_back(num);
            }
            else if(num > pivot){
                greater_than.push_back(num);
            }
            else{
                ++cnt;
            }
        }

        ans.insert(ans.end(), cnt, pivot);
        ans.insert(ans.end(), greater_than.begin(), greater_than.end());

        return ans;
    }
};