class Solution {
public:
    vector<int> minOperations(string boxes) {

        int n = boxes.length();
        vector<int> ballsToTheLeft(n, 0);
        vector<int> ballsToTheRight(n, 0);
        int presum = 0;

        //calculate the number of balls to the left for each box
        for (int i = 0; i < n; i++) {
            ballsToTheLeft[i] = presum;
            presum += (boxes[i] - '0');
        }

        presum = 0;

        //calculate the number of balls to the right for each box
        for (int i = n - 1; i >= 0; i--) {
            ballsToTheRight[i] = presum;
            presum += (boxes[i] - '0');
        }

        vector<int> OperL(n, 0); //Number of operations to get balls from the left, for each box
        vector<int> OperR(n, 0); //Number of operations to get balls from the right, for each box

        for (int i = 1; i < n; i++) {
            OperL[i] = OperL[i - 1] + ballsToTheLeft[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            OperR[i] = OperR[i + 1] + ballsToTheRight[i];
        }

        //create final answer array by adding finalL and finalR
        for (int i = 0; i < n; i++) {
            OperL[i] += OperR[i];
        }

        return finalL;

    }
};