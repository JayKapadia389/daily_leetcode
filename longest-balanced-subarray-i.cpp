class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans = 0, n = nums.size();

        for(int i = 0; i < n; ++i){
            unordered_set<int> s;
            int even = 0, odd = 0;
            
            for(int j = i; j < n; ++j){
                if(s.find(nums[j]) == s.end()){
                    s.insert(nums[j]);
                    if(nums[j]%2 == 0){
                        ++even;
                    }
                    else{
                        ++odd;
                    }
                }

                if(even == odd){
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};