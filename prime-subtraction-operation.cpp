class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {

        vector<int> primeNums;
        bool flag;

        for (int i = 2; i <= 1009; i++) {

            flag = 0;

            for (int j = 2; j <= i / 2; j++) {
                if (i % j == 0) {
                    flag = 1;
                }
            }

            if (!flag) {
                primeNums.push_back(i);
            }

        }

        int primeNumsLen = primeNums.size();
        int n = nums.size();
        int curr, newNum;

        for (int i = n - 2; i >= 0; i--) {

            curr = nums[i];

            if (!(curr < nums[i + 1])) {

                for (int j = 0; j < primeNumsLen; j++) {

                    newNum = curr - primeNums[j];

                    if (newNum <= 0) {
                        return false;
                    }

                    else if (newNum < nums[i + 1]) {
                        nums[i] = newNum;
                        break;
                    }

                }

            }

        }

        return true;

    }
};