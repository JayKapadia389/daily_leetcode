class Solution {
public:
    bool sumGame(string num) {
        int q0 = 0, q1 = 0, n0 = 0, n1 = 0, n = num.size();

        for(int i = 0; i < n/2; ++i) {
            if(num[i] == '?') {
                ++q0;
            }
            else {
                n0 += (num[i] - '0');
            }
        }

        for(int i = n/2 ; i < n; ++i) {
            if(num[i] == '?') {
                ++q1;
            }
            else {
                n1 += (num[i] - '0');
            }
        }

        if(((q0 + q1) % 2) != 0) {
            return true;
        }

        if((q0 + q1) == 0) {
            return n0 != n1;
        }

        if(q0 > q1) {
            swap(q0, q1);
            swap(n0, n1);
        }

        return (n0 - n1) != (9 * (q1 - q0) / 2);
    }
};