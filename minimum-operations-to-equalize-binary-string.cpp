class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length(), init = 0;
        set<int> s_even;
        set<int> s_odd;

        for (int i = 0; i <= n; i += 2) {
            s_even.insert(i);
        }

        for (int i = 1; i <= n; i += 2) {
            s_odd.insert(i);
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                ++init;
            }
        }

        queue<int> q;
        q.push(init);
        s_odd.erase(init);
        s_even.erase(init);
        int dis = 0;


        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                int z = q.front();
                q.pop();
                if (z == 0) {
                    return dis;
                }

                int i_low = max(0, k - (n - z));
                int i_high = min(k, z);
                int z_low  = z + k - 2 * i_high;  // min reachable z'
                int z_high = z + k - 2 * i_low;   // max reachable z'
                set<int>& s = ((z + k) % 2) ? s_odd : s_even;
                auto it = s.lower_bound(z_low);

                while (it != s.end() && (*it <= z_high)) {
                    q.push(*it);
                    it = s.erase(it);
                }
            }

            ++dis;
        }

        return -1;
    }
};