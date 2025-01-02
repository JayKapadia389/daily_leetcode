class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size(), sum = 0;
        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            diff[i] = gas[i] - cost[i];
            sum += diff[i];
        }

        if (sum < 0)
            return -1;

        int idx = 0;
        sum = 0;

        for (int i = 0; i < n; i++) {
            sum += diff[i];

            if (sum < 0) {
                idx = i + 1;
                sum = 0;
            }
        }

        if (sum >= 0) {
            return idx;
        }

        return -1;

    }
};