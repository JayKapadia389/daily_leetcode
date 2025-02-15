class Solution {
public:
    bool validSplit(int original, string& s, vector<bool>& m) {
        int sum = 0, i = 0;

        for (int j = 0; j < m.size(); ++j) {
            if (m[j]) {
                sum += stoi(s.substr(i, j - i + 1));
                i = j + 1;
            }
        }
        sum += stoi(s.substr(i));

        return sum == original;
    }

    bool good(int original, string& s, int len, vector<bool>& m, int sum, int idx) {
        if (sum > original) return false;  // Prune early
        if (idx == len) return sum == original;  // If we reached the end, check validity

        int num = 0;
        for (int i = idx; i < len; ++i) {
            num = num * 10 + (s[i] - '0');  // Convert substring to integer
            if (num > original) break;  // Prune large numbers

            if (good(original, s, len, m, sum + num, i + 1)) return true;
        }

        return false;
    }

    int punishmentNumber(int n) {
        int sum = 0;

        for (int i = 1; i <= n; ++i) {
            int square = i * i;
            string s = to_string(square);
            vector<bool> m(s.length() - 1, false);

            if (good(i, s, s.length(), m, 0, 0)) {
                sum += square;
            }
        }

        return sum;
    }
};
