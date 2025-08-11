class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int> powers;

        for(int i = 0; i < 31; ++i){
            if((1 << i) & n){
                powers.push_back(1 << i);
            }
        }

        vector<int> ans(queries.size());
        for(int i = 0; i < queries.size(); ++i){
            auto q = queries[i];
            long long product = 1;

            for(int idx = q[0]; idx <= q[1]; ++idx){
                product = (product * powers[idx]) % mod ; 
            }

            ans[i] = product;
        }
        return ans;
    }
};