class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        for(auto& num : nums){
            num = abs(num);
        }

        sort(nums.begin(), nums.end());

        int l = 0, r = 0 , n = nums.size();
        long long ans = 0;

        while(r < n){
            if(l == r){
                ++r;
                continue;
            }

            if(abs(nums[l] - nums[r]) <= nums[l]){
                ans += (r - l);
                ++r;
            }
            else{
                ++l;
            }
        }

        return ans;
    }
};