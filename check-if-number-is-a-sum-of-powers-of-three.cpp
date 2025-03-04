class Solution {
public:

    int n_;

    bool recc(long long& sum, int& power) {
        if (sum == n_) {
            return true;
        }

        if (power == 16) {
            return false;
        }

        if (recc(sum, ++power)) {
            return true;
        }

        --power;
        sum += pow(3, power);

        if (recc(sum, ++power)) {
            return true;
        }

        --power;
        sum -= pow(3, power);

        return false;
    }

    bool checkPowersOfThree(int n) {

        n_ = n;
        long long sum = 0;
        int power = 0;
        return recc(sum, power);

    }
};