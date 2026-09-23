class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int y, total = 0, n = nums.size();
        int len = INT_MIN;
        int sum = 0;

        for(auto num : nums) {
            total += num;
        }

        y = total - x;
        if(total == x) {
            return n;
        }
        else if(total < x){
            return -1;
        }
        
        for(int i = 0, j = 0; j < n && i < n; ++j) {
            sum += nums[j];

            while(sum > y && i < n) {
                sum -= nums[i];
                ++i;
            }

            if(sum == y) {
                len = max(len, j - i + 1);
            }
        }

        if(len == INT_MIN){
            return -1;
        }
        return n - len;
    }
};