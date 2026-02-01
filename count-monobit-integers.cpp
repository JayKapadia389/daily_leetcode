// contest
// not upsolved

class Solution {
public:
    int countMonobit(int n) {
        int base = 0, cnt = 0;
        while(base <= n){
            ++cnt;
            base <<= 1;
            base |= 1;
        }
        return cnt;
    }
};