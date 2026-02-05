// Solution 1: O(n) time, O(n) space
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n);

        for(int i = 0; i < n; ++i){
            int j = (i+nums[i])%n;
            if(j < 0){
                j += n;
            }
            results[i] = nums[j];
        }

        return results;
    }
};

// Solution 2: O(n) time, O(1) space
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        int OFFSET = 100;
        int MASK = (1 << 8) - 1; 

        for(auto& num : nums){
            num += OFFSET;
        }

        for(int i = 0; i < n; ++i){
            int shift = nums[i] - OFFSET;
            int j = (((i + shift)%n)+n)%n;
            int original = nums[j] & MASK;
            nums[i] |= (original << 8);
        }

        for(auto& num : nums){
            num >>= 8;
            num -= OFFSET;
        }

        return nums;
    }
};