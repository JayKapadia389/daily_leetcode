class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int m = mat.size(), n = mat[0].size(), s = m * n;

        vector<int> rowFreq(m, 0);
        vector<int> colFreq(n, 0);

        map<int, pair<int, int>> coords;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                coords[mat[i][j]] = { i , j };
            }
        }

        int cell;

        for (int k = 0; k < s; k++) {
            cell = arr[k];
            auto [i, j] = coords[cell];

            ++rowFreq[i];
            ++colFreq[j];

            if (rowFreq[i] == n || colFreq[j] == m) {
                return k;
            }
        }

        return -1;
    }
};