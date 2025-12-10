const int MOD = 1e9 + 7;
class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int f = complexity[0];
        long long ans = 1;

        for(int i = 1; i < complexity.size(); ++i){
            if(complexity[i] <= f){
                return 0;
            }

            ans = (ans * i) % MOD;
        }

        return ans;
    }
};