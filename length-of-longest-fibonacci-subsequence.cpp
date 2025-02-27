class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {

        int ans = 0, n = arr.size();

        for (int i = 0; i < n - 2; ++i) {
            for (int j = i + 1; j < n - 1; ++j) {

                int f = arr[i];
                int s = arr[j];
                int len = 2;
                int sum = f + s;

                for (int k = j + 1; k < n; ++k) {
                    if (arr[k] == sum) {
                        ++len;
                        ans = max(ans, len);

                        f = s;
                        s = sum;
                        sum = f + s;
                    }
                }

            }
        }

        return ans;

    }
};