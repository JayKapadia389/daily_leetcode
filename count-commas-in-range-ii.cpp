class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        int i = 1;
        long long j = 9;

        while(n != 0) {
            long long cut = min(n, j);
            n -= cut;

            int num_comma_per_number = (i / 3) - ((i % 3 == 0)? 1 : 0);

            ans += (num_comma_per_number * cut);
            i += 1;
            j *= 10;
        }

        return ans;
    }
};