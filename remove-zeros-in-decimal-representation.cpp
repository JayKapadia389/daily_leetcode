class Solution {
public:
    long long removeZeros(long long n) {
        string s = to_string(n);
        int size = log10(n) + 1; // number of digits
        string t = "";
        t.reserve(size);

        for(auto digit : s){
            if(digit != '0'){
                t += digit;
            }
        }

        return stoll(t);
    }
};