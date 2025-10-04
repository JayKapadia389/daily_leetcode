#define f numBottles
#define c numExchange

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int e = 0, sum = 0;

        while(f > 0){
            sum += f;

            e = f + e;
            f = e / c;
            e = e % c;
        }

        return sum;
    }
};