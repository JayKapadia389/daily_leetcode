class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51, 0);
        for(auto num : nums){
            ++freq[num];
        }

        if(k == 1){
            for(int i = 50; i >= 0; --i) {
                if(freq[i] == 1){
                    return i;
                }
            }

            return -1;
        }
        else{
            if(k == n){
                for(int i = 50; i >= 0; --i){
                    if(freq[i] != 0){
                        return i;
                    }
                }
            }

            if(nums[0] == nums[n - 1]){
                return -1;
            }

            int ans = -1;

            if(freq[nums[0]] == 1){
                ans = max(ans, nums[0]);
            }

            if(freq[nums[n - 1]] == 1){
                ans = max(ans, nums[n - 1]);
            }

            return ans;
        }
    }
};