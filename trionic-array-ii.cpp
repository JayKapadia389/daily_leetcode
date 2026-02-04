class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        long long answer = LLONG_MIN;
        long long temp_sum = nums[0];
        int l = 0;
        int p = 0;
        int q = 0;

        for(int r = 1; r < n; ++r){
            temp_sum += nums[r];
            
            if(nums[r] == nums[r-1]){
                l = r;
                temp_sum = nums[r];
            }
            else if(nums[r] < nums[r-1]){
                if(r > 1 && nums[r-2] < nums[r-1]){
                    p = r-1;

                    while(l < q) temp_sum -= nums[l++];
                    while(l < p-1 && nums[l] < 0) temp_sum -= nums[l++];
                }
            }
            else{
                if(r > 1 && nums[r-1] < nums[r-2]) q = r-1;
                if(l < p && p < q) answer = max(answer, temp_sum); 
            }
        }

        return answer;
    }
};