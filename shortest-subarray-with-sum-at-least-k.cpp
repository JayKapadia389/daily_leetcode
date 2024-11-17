class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int ansLen = INT_MAX;
        int currSum = 0;
        int left = 0;

        for (int right = 0; right < n; right++) {

            currSum += nums[right];

            if (currSum <= 0) {
                left = right + 1;
                currSum = 0;
            }
            else if (currSum >= k) {

                cout << "yes";

                ansLen = min(ansLen, right - left + 1);

                while ((currSum - nums[left]) >= k) {
                    currSum -= nums[left];
                    ++left;
                    ansLen = min(ansLen, right - left + 1);
                }

            }

        }

        if (ansLen == INT_MAX) {
            return -1;
        }

        else {
            return ansLen;
        }

    }
};