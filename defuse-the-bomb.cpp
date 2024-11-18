class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {

        int n = code.size();
        int sum = 0;

        vector<int> ans(n, 0);

        if (k == 0) {
            return ans;
        }
        else if (k > 0) {

            for (int i = 1; i <= k; i++) {
                sum += code[i];
            }

            ans[0] = sum;

            for (int i = 1; i < n; i++) {
                sum -= code[i];

                if (i + k >= n) {
                    sum += code[i + k - n];
                }
                else {
                    sum += code[i + k];
                }

                ans[i] = sum;
            }

        }
        else {

            for (int i = -1; i >= k; i--) {
                sum += code[n - 1 + i];
            }

            ans[n - 1] = sum;

            for (int i = n - 2; i >= 0; i--) {
                sum -= code[i];

                if ((i + k) >= 0) {
                    cout << (i + k) << " ";
                    sum += code[i + k];
                }
                else {
                    sum += code[n + (i + k)];
                }

                ans[i] = sum;
            }

        }

        return ans;

    }
};