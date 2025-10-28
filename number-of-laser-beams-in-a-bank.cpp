class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, curr, m = bank.size(), n = bank[0].size();
        long long ans = 0;

        for(int i = 0; i < m; ++i){
            curr = 0;

            for(int j = 0; j < n; ++j){
                curr += (bank[i][j] - '0');
            }

            if(curr){
                ans += prev * curr;
                prev = curr;
            }
        }
        return ans; 
    }
};