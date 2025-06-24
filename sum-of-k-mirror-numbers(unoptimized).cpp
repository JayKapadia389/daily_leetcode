//91/97 passed TLE

class Solution {
public:

    // Generate even-length palindrome: 1221 from 12
    long long gen_2d_palindrome(int num) {
        string s = to_string(num);
        string rev = s;
        reverse(rev.begin(), rev.end());
        return stoll(s + rev);
    }

    // Generate odd-length palindrome: 121 from 12
    long long gen_2d_minus_1_palindrome(int num) {
        if (num >= 1 && num <= 9) return num;
        string s = to_string(num);
        string rev = s;
        reverse(rev.begin(), rev.end());
        rev = rev.substr(1);  // drop the first digit to make it odd-length
        return stoll(s + rev);
    }

    // Convert to base-k and return as string
    string to_base_k(long long num, int k) {
        string res = "";
        while (num > 0) {
            res = to_string(num % k) + res;
            num /= k;
        }
        return res;
    }

    // Check if a string is a palindrome
    bool is_pal(const string& s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    long long kMirror(int k, int n) {
        long long ans = 0;
        int count = 0;
        int l = 1, r = 10;

        while (count < n) {
            // 2d - 1 digit palindromes
            for (int i = l; i < r && count < n; ++i) {
                long long num = gen_2d_minus_1_palindrome(i);
                if (is_pal(to_base_k(num, k))) {
                    ans += num;
                    ++count;
                }
            }

            // 2d digit palindromes
            for (int i = l; i < r && count < n; ++i) {
                long long num = gen_2d_palindrome(i);
                if (is_pal(to_base_k(num, k))) {
                    ans += num;
                    ++count;
                }
            }

            l *= 10;
            r *= 10;
        }

        return ans;
    }
};