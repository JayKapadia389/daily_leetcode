class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int mx_len = 0, n = nums.size();

        for(int i = 0, j = 0; j < n; ++j) {
            int curr_num = nums[j];
            ++freq[curr_num];

            while(freq[curr_num] > k){
                --freq[nums[i]];
                ++i;
            }

            mx_len = max(mx_len, j - i + 1);
        }

        return mx_len;
    }
};