class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        map<int, int> freq;
        int common = 0, n = A.size();
        vector<int> C(n);

        for (int i = 0; i < n; i++) {
            ++freq[A[i]];

            if (freq[A[i]] == 2)
                ++common;

            ++freq[B[i]];

            if (freq[B[i]] == 2)
                ++common;

            C[i] = common;
        }

        return C;

    }
};