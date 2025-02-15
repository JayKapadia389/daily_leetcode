class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        priority_queue<long long, vector<long long>, greater<>> pq;

        for (auto i : nums) {
            pq.push(i);
        }

        long long noo = 0;

        while (pq.top() < k) {
            ++noo;

            long long f = pq.top();
            pq.pop();
            long long s = pq.top();
            pq.pop();

            pq.push(min(f, s) * 2 + max(f, s));
        }

        return noo;

    }
};