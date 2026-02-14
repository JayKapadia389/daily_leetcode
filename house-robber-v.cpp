// contest
// 2 pointer + 1D DP
class Solution {
public:
    long long rob(vector<int>& nums, vector<int>& colors) {
        long long ans = 0;
        int n = nums.size();

        vector<long long> nums_ll(n);
        for(int i = 0; i < n; ++i){
            nums_ll[i] = nums[i];
        }

        for(int l = 0, r = 0; r < n; ++r){
            if(r+1 < n && colors[r+1] == colors[r]){
                continue;
            }

            if(l+2 <= r){
                nums_ll[l+2] += nums_ll[l];
            }

            for(int i = l+3; i <= r; ++i){
                nums_ll[i] += max(nums_ll[i-3], nums_ll[i-2]);
            }

            long long temp = nums_ll[r];

            if((r - l + 1) > 1){
                temp = max(temp, nums_ll[r-1]);
            }

            ans += temp;
            l = r+1;
        }

        return ans;
    }
};