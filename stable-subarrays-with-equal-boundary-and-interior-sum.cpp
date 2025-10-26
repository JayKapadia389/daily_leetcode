#define ll long long

class Solution {
public:
    long long countStableSubarrays(vector<int>& capacity) {
        ll ans = 0, pre = 0, n = capacity.size();
        unordered_map<int, unordered_map<ll, ll>> m;

        for(int i = 0; i < n; ++i){
            int x = capacity[i];
            ll y = pre - x;

            if(m.find(x) != m.end() && m[x].find(y) != m[x].end())
                ans += m[x][y];

            pre += x;
            ++m[x][pre]; 
            if (i > 0 && x == 0 && capacity[i - 1] == 0)
                --ans;
        }

        return ans;
    }
};