class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n = s.length();

        vector<vector<vector<bool>>> arr(n,
            vector<vector<bool>>(2,
                vector<bool>(26, 0)
            )
        );

        bool left = 0, right = 1;

        for (int i = 1; i < n; i++) {
            arr[i][left] = arr[i - 1][left];
            arr[i][left][s[i - 1] - 97] = 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            arr[i][right] = arr[i + 1][right];
            arr[i][right][s[i + 1] - 97] = 1;
        }

        vector<vector<bool>> m(26, vector<bool>(26, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (arr[i][left][j] == 1 && arr[i][right][j] == 1) {
                    m[s[i] - 97][j] = true;
                }
            }
        }

        int ans = 0;

        for (auto vec : m) {
            for (int i = 0; i < 26; i++) {
                ans += vec[i];
            }
        }

        return ans;

    }
};