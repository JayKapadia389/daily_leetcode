class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i = n; ; ++i){
            int pro = 1;
            int num = i;

            while(num != 0){
                pro *= (num % 10);
                num /= 10;
            }

            if(pro % t == 0){
                return i;
            }
        }
        return 0;
    }
};