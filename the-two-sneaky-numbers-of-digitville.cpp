class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<bool> present(nums.size()-2,0);
        vector<int> ans;
        for(auto num : nums){
            if(present[num]) ans.push_back(num);
            present[num] = 1;
        }
        return ans;
    }
};