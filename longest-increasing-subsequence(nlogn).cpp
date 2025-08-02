class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;

        for(auto num : nums){
            auto it = lower_bound(res.begin(), res.end(), num);

            if(it == res.end()){
                res.push_back(num);
            }
            else{
                *it = num;
            }
        }
        return res.size();
    }
};