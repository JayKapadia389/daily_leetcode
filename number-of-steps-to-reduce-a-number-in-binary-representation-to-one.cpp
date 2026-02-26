// my - greedy
class Solution {
public:
    int numSteps(string s) {
        int steps = 0, n = s.length();
        int i = n - 1;

        while(s[i] == '0') --i;
        steps += n - i - 1;

        if(i == 0) return steps;

        steps+=1;
        int len = 0;
        bool b = 1;
        for(; i >= 0; --i){
            ++len;
            if(i == 0 || s[i - 1] != s[i]){
                steps += (len * (b?1:2));
                len = 0;
                b = !b;
            }
        }

        return steps;
    }
};

// editorial - more greedy
class Solution {
public:
    int numSteps(string s) {
        int N = s.size();

        int operations = 0;
        int carry = 0;
        for (int i = N - 1; i > 0; i--) {
            if (((s[i] - '0') + carry) % 2) {
                operations += 2;
                carry = 1;
            } else {
                operations++;
            }
        }

        return operations + carry;
    }
}; 