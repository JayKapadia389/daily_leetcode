class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;

        // Both phase
        long long cost = min(cost1 + cost2, costBoth);
        ans += (cost * min(need1, need2));

        // Remaining phase
        int diff = abs(need1 - need2);
        cost = min(costBoth, (need1 > need2)? cost1 : cost2);

        ans += (diff * cost);

        return ans;
    }
};