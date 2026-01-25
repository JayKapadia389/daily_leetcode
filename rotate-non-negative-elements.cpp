class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> non_neg;

        for(const auto& num : nums){
            if(num >= 0){
                non_neg.push_back(num);
            }
        }

        int m = non_neg.size(), idx = 0;
        for(auto& num : nums){
            if(num >= 0){
                int idx2 = (idx + k) % m;
                num = non_neg[idx2];
                ++idx;
            }
        }
        
        return nums;
    }
};