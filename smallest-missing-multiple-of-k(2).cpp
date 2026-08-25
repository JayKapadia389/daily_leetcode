class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int next_multiple = 1, n = nums.size();

        sort(nums.begin(), nums.end());

        for(auto& num : nums){
            if(num % k == 0) {
                int multiple = num / k;
                
                if(multiple == next_multiple){
                    ++next_multiple;
                }
                else if(multiple > next_multiple){
                    break;
                }
            }
        }

        return k * next_multiple;
    }
};