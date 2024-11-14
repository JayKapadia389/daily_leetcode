class Solution {
public:

    bool viable(int mid, int& n, vector<int>& quantities) {
        int want = 0;
        float midf = static_cast<float>(mid);

        for (auto q : quantities) {
            want += ceil(q / midf);
        }

        if (want > n) {
            return false;
        }
        else {
            return true;
        }
    }

    int minimizedMaximum(int n, vector<int>& quantities) {

        int x = INT_MAX, mid;

        int i = 1;
        int j = 0;

        for (auto q : quantities) {
            j = max(j, q);
        }

        while (i <= j) {

            mid = (i + j) / 2;

            if (viable(mid, n, quantities)) {
                x = min(x, mid);
                j = mid - 1;
            }
            else {
                i = mid + 1;
            }

        }
        return x;
    }
};