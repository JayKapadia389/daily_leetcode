class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {

        int neg = 0, n = matrix.size(), minimum = INT_MAX, x;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                x = matrix[i][j];

                if (x > 0) {
                    ans += x;
                    minimum = min(minimum, x);
                }
                else if (x < 0) {
                    ans += (x * (-1));
                    minimum = min(minimum, (x * (-1)));
                    ++neg;
                }
                else {
                    minimum = 0;
                }

            }
        }

        if (neg % 2 == 0 || minimum == 0) {
            return ans;
        }
        else {
            return (ans - (2 * minimum));
        }

    }
};