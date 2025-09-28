class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0, n = nums.size();

        for(int i = 0; i < n - 2; ++i){
            for(int j = i+1, k = i+2; j < n-1; ++j){
                if(k <= j) k = j+1;
                int two_sum = nums[i] + nums[j];

                while(k < n && two_sum > nums[k]){
                    ans = max(ans, two_sum + nums[k]);
                    ++k;
                }
            }
        }

        return ans;
    }
};