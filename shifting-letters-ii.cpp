class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {

        int n = s.length(), m = shifts.size();

        vector<vector<int>> fShifts;
        vector<vector<int>> bShifts;

        for (auto i : shifts) {
            if (i[2] == 0) {
                bShifts.push_back(i);
            }
            else {
                fShifts.push_back(i);
            }
        }

        vector<int> intermediate(n, 0);
        vector<int> final(n, 0);
        int presum = 0;

        //process fShifts

        for (auto i : fShifts) {
            ++intermediate[i[0]];

            if (i[1] + 1 < n) {
                --intermediate[i[1] + 1];
            }
        }

        cout << "1" << endl;
        for (auto i : intermediate) {
            cout << i << " ";
        }

        for (int i = 0; i < n; i++) {
            presum += intermediate[i];

            final[i] += presum;
        }

        //process bShift

        for (int i = 0; i < n; i++) {
            intermediate[i] = 0;
        }
        presum = 0;

        for (auto i : bShifts) {
            ++intermediate[i[0]];

            if (i[1] + 1 < n) {
                --intermediate[i[1] + 1];
            }
        }

        cout << endl;
        cout << "2" << endl;
        for (auto i : intermediate) {
            cout << i << " ";
        }

        for (int i = 0; i < n; i++) {
            presum += intermediate[i];

            final[i] -= presum;
        }

        cout << endl;

        cout << "3" << endl;
        for (auto i : final) {
            cout << i << " ";
        }

        //use final to shift

        for (int i = 0; i < n; i++) {
            final[i] = final[i] % 26;
        }

        cout << endl;

        for (int i = 0; i < n; i++) {
            int val = s[i] += final[i];

            cout << val << " ";

            if (val > 'z') {
                s[i] = 96 + (val - 'z');
            }

            else if (val < 'a') {
                s[i] = 'z' - ('a' - val) + 1;
            }
            else {
                s[i] = val;
            }

        }
        return s;
    }

};