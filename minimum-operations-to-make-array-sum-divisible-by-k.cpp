class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;

        for(auto num : nums){
            sum = (sum + num) % k;
        }

        return sum;
    }
};