class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0, sum = 0;
        int invalid_count = 0, j;
        map<int, int> freq;
        int n = nums.size();


        for (int i = 0; i < k; i++) {
            ++freq[nums[i]];
            sum += nums[i];
            if (freq[nums[i]] == 2) {
                ++invalid_count;
            }
        }

        if (invalid_count == 0) {
            ans = max(ans, sum);
        }

        for (int i = k; i < n; i++) {
            ++freq[nums[i]];
            sum += nums[i];
            if (freq[nums[i]] == 2) {
                ++invalid_count;
            }


            j = i - k;
            --freq[nums[j]];
            sum -= nums[j];
            if (freq[nums[j]] == 1) {
                --invalid_count;
            }

            if (invalid_count == 0) {
                ans = max(ans, sum);
            }
        }

        return ans;
    }
};
