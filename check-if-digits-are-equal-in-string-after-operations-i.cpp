class Solution {
public:
    bool hasSameDigits(string s) {
        int n = s.length();
        vector<int> v;

        for(auto digit : s){
            v.push_back(digit - 0);
        }

        for(int i = n; i > 2; --i){
            for(int j = 0; j < n-1; ++j){
                v[j] = (v[j] + v[j+1])%10;
            }
        }

        return v[0] == v[1];
    }
};


// Better time and space
//
// class Solution {
// public:
//     bool hasSameDigits(string s) {
//         int n = s.length();
//         for (int i = 1; i <= n - 2; i++) {
//             for (int j = 0; j <= n - 1 - i; j++) {
//                 s[j] = ((s[j] - '0') + (s[j + 1] - '0')) % 10 + '0';
//             }
//         }
//         return s[0] == s[1];
//     }
// };