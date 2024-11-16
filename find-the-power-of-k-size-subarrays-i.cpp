class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {

        int n = nums.size();
        int m = n - k + 1;

        vector<int> answer(m);
        bool flag;

        for (int i = 0; i < m; i++) {

            flag = 0;

            for (int j = 1; j < k; j++) {
                if (nums[i + j] != nums[i + j - 1] + 1) {
                    flag = 1;
                }
            }

            if (flag == 1) {
                answer[i] = -1;
            }
            else {
                cout << i << " " << k << endl;
                answer[i] = nums[i + k - 1];
            }

        }

        return answer;

    }
};