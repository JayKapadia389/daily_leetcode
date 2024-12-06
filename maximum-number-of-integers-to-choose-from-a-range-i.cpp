class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {

        int m = banned.size();

        sort(banned.begin(), banned.end());

        for (auto i : banned)
            cout << i << endl;

        int iter = 0, c = 0, sum = 0;

        for (int i = 1; i <= n; i++) {

            if (sum + i > maxSum) {
                break;
            }

            if (iter != m && i == banned[iter]) {

                int curr = banned[iter];

                while (iter != m && banned[iter] == curr) {
                    ++iter;
                }
            }

            else {

                sum += i;
                ++c;

                cout << i << " " << sum << " " << c << endl;
            }

        }

        return c;

    }
};