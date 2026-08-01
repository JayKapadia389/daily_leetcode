// Solution 1
class Solution {
public:
    int minimumPushes(string word) {
        int cnt = 0;
        int len = word.size();
        int i = 1;
        while(len != 0){
            int some = min(len, 8);
            len -= some;
            cnt += (i * some);
            ++i;
        }
        return cnt;
    }
};

// Solution 2
class Solution {
public:
    int minimumPushes(string word) {
        int len = word.size();
        int quo = len / 8;
        int rem = len % 8;
        return 4 * quo * (quo + 1) + (quo + 1) * rem;
    }
};