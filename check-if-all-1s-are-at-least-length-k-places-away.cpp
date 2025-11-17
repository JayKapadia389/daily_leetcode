class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int var = 0;

        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 1){
                if(var == 0){
                    var = k;
                }
                else{
                    return false;
                }
            }
            else{
                var = max(var-1,0);
            }
        }

        return true;
    }
};