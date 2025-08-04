class Solution {
private:
    bool shift_left(vector<vector<int>>::iterator& lptr,
                    vector<vector<int>>::iterator rptr,
                    int startPos, int k, int& curr) {
        while (lptr <= rptr) {
            int l_dis = abs(startPos - (*lptr)[0]);
            int r_dis = abs(startPos - (*rptr)[0]);

            if (
                l_dis == 0 || 
                r_dis == 0 || 
                ((*lptr)[0] < startPos && (*rptr)[0] < startPos) ||
                ((*lptr)[0] > startPos && (*rptr)[0] > startPos)
            ) {
                if (max(l_dis, r_dis) <= k) {
                    break;
                }
            } else {
                if ((max(l_dis, r_dis) + 2 * min(l_dis, r_dis)) <= k) {
                    break;
                }
            }

            curr -= (*lptr)[1];
            ++lptr;
        }

        return (lptr <= rptr);
    }

public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        auto lptr = lower_bound(
            fruits.begin(), fruits.end(),
            vector<int>{startPos - k, 0},
            [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            }
        );

        if (lptr == fruits.end()) {
            return 0;
        }

        auto rptr = lptr;
        // int curr = (*lptr)[1];
        int curr = 0;
        int ans = 0;

        // ++rptr;
        while (rptr < fruits.end()) {
            int l_dis = abs(startPos - (*lptr)[0]);
            int r_dis = abs(startPos - (*rptr)[0]);

            if (
                l_dis == 0 || 
                r_dis == 0 || 
                ((*lptr)[0] < startPos && (*rptr)[0] < startPos) ||
                ((*lptr)[0] > startPos && (*rptr)[0] > startPos)
            ) {
                if (max(l_dis, r_dis) <= k) {
                    curr += (*rptr)[1];
                } else {
                    if (!shift_left(lptr, rptr, startPos, k, curr)) {
                        break;
                    }
                    continue; // skip rptr++ and ans update
                }
            } else {
                if ((max(l_dis, r_dis) + 2 * min(l_dis, r_dis)) <= k) {
                    curr += (*rptr)[1];
                } else {
                    if (!shift_left(lptr, rptr, startPos, k, curr)) {
                        break;
                    }
                    continue; // skip rptr++ and ans update
                }
            }

            ans = max(ans, curr);
            ++rptr;
        }

        return ans;
    }
};
