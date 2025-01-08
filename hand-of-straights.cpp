#define k groupSize

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        int n = hand.size();

        if (n % k != 0)
            return false;

        sort(hand.begin(), hand.end());

        map<int, int> m;
        queue<int> q;

        ++m[hand[0]];
        q.push(hand[0]);
        int uniq = hand[0], curr;

        for (int i = 1; i < n; i++) {
            curr = hand[i];
            ++m[curr];
            if (curr != uniq) {
                uniq = curr;
                q.push(uniq);
            }
        }

        int f;

        while (!q.empty()) {
            f = q.front();
            for (int i = f; i < f + k; ++i) {
                if (m[i] == 0) {
                    return false;
                }

                --m[i];
            }

            while (!q.empty() && m[q.front()] == 0) {
                q.pop();
            }
        }

        return true;

    }
};