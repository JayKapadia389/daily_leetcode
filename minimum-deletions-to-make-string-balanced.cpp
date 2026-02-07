// Worst solution
// O(n) time - 3 pass
// O(n) space - 2n.
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> zeros(n); // 'a'
        vector<int> ones(n); // 'b'

        zeros[n-1] = (s[n-1] == 'a') ? 1 : 0;
        for(int i = n - 2; i >= 0; --i){
            zeros[i] = (s[i] == 'a')? zeros[i+1] + 1 : zeros[i+1];
        }

        ones[0] = (s[0] == 'b') ? 1 : 0;
        for(int i = 1; i < n; ++i){
            ones[i] = (s[i] == 'b')? ones[i-1] + 1 : ones[i-1];
        }

        int mn = n;
        mn = min(mn, 0 + zeros[0]);
        for(int i = 0; i < n-1; ++i){
            mn = min(mn, ones[i] + zeros[i+1]);
        }
        mn = min(mn, ones[n-1] + 0);

        return mn;
    }
};


// Space optimized 2D-DP
// O(n) time - single pass
// O(1) space
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        vector<int> prev(2, 0);
        vector<int> curr(2, 0);

        for(int i = n-1; i >= 0; --i){
            int take = INT_MIN, not_take = INT_MIN;
                        
            // !last_b (0)
            not_take = prev[0];
            if(s[i] == 'b'){
                take = 1 + prev[1];
            }
            else{
                take = 1 + prev[0];
            }
            curr[0] = max(take, not_take);

            // last_b (1)
            take = INT_MIN, not_take = INT_MIN;
            not_take = prev[1];
            if(s[i] == 'b'){
                take = 1 + prev[1];
            }
            curr[1] = max(take, not_take);

            // roll
            prev = curr;
        }

        return (n - curr[0]);
    }
};