class Solution {
public:

    int m_, n_;

    bool ingrp(vector<vector<int>>& matrix, int& i, int& j) {

        bool flag = 0;

        for (int k = 0; k < n_; k++) {
            if (matrix[i][k] != matrix[j][k]) {
                flag = 1;
            }
        }

        if (flag == 0) {
            return true;
        }

        flag = 0;

        for (int k = 0; k < n_; k++) {
            if (matrix[i][k] == matrix[j][k]) {
                flag = 1;
            }
        }

        if (flag == 0) {
            return true;
        }

        return false;

    }

    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {

        m_ = matrix.size();
        n_ = matrix[0].size();
        int maxGrp = 0, grp;

        for (int i = 0; i < m_; i++) {

            grp = 1;

            for (int j = i + 1; j < m_; j++) {

                if (ingrp(matrix, i, j)) {
                    ++grp;
                }

            }

            maxGrp = max(grp, maxGrp);

        }

        return maxGrp;

    }
};