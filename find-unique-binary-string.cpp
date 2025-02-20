class Solution {
public:
    int _n;

    int convert(string num) {

        int res = 0, i = _n - 1;
        for (auto c : num) {
            res += (c - '0') * pow(2, i);
            --i;
        }
        return res;
    }

    bool find(map<int, bool>& m, int& ans, int& size) {

        if (size == _n) {
            if (m[ans] == 0) {
                return true;
            }
            return false;
        }

        //check 0
        ++size;
        if (find(m, ans, size)) {
            return true;
        }

        //check 1
        ans += pow(2, size - 1) * 1;
        if (find(m, ans, size)) {
            return true;
        }
        ans -= pow(2, size - 1) * 1;
        --size;

        return false;

    }

    string tostr(int ans) {
        string str = "";

        for (int i = 0; i < _n; ++i) {
            str = to_string(ans % 2) + str;
            ans /= 2;
        }
        return str;
    }

    string findDifferentBinaryString(vector<string>& nums) {

        map<int, bool> m;
        _n = nums.size();

        for (auto num : nums) {
            m[convert(num)] = 1;
        }

        int ans, size = 0;
        find(m, ans, size);

        return tostr(ans);

    }
};