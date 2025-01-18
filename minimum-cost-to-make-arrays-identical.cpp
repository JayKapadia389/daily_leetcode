class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {

        long long ans, cost = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            cost += abs(arr[i] - brr[i]);
        }

        ans = cost;

        cost = k;

        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        for (int i = 0; i < n; i++) {
            cost += abs(arr[i] - brr[i]);
        }

        ans = min(ans, cost);

        return ans;

    }
};