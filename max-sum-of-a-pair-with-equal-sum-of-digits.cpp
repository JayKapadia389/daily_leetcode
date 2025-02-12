class Solution {
public:

    int findSod(int num) {
        int sod = 0;

        while (num != 0) {
            sod += num % 10;
            num /= 10;
        }

        return sod;
    }

    int maximumSum(vector<int>& nums) {

        int n = nums.size();
        map<int, int> m;
        int sum = -1;

        sort(nums.begin(), nums.end(), greater<>());

        for (int i = 0; i < n; ++i) {
            int sod = findSod(nums[i]);

            if (m.find(sod) == m.end()) {
                m[sod] = i;
            }
            else {
                sum = max(sum, nums[m[sod]] + nums[i]);
            }
        }

        return sum;

    }
};