class Solution {
public:

    int trapRainWater(vector<vector<int>>& heightMap) {

        int m = heightMap.size(), n = heightMap[0].size(), mx, mn;

        vector<vector<int>> dir = {
            {}
        }

        vector<int> rowHeight(m);
        vector<int> colHeight(n);

        for (int i = 0; i < m; i++) {
            mn = INT_MAX;
            for (int j = 0; j < n; j++) {
                mn = min(mn, heightMap[i][j]);
            }
            rowHeight[i] = mn;
        }

        for (int j = 0; j < n; j++) {
            mn = INT_MAX;
            for (int i = 0; i < m; i++) {
                mn = min(mn, heightMap[i][j]);
            }
            colHeight[j] = mn;
        }

        vector<int> lmax(n);
        vector<int> rmax(n);
        vector<int> tmax(m);
        vector<int> bmax(m);

        mx = 0;
        for (int j = 0; j < n; j++) {
            lmax[j] = mx;
            mx = max(mx, colHeight[j]);
        }

        mx = 0;
        for (int j = n - 1; j >= 0; j--) {
            rmax[j] = mx;
            mx = max(mx, colHeight[j]);
        }

        mx = 0;
        for (int i = 0; i < m; i++) {
            tmax[i] = mx;
            mx = max(mx, rowHeight[i]);
        }

        mx = 0;
        for (int i = m - 1; i >= 0; i--) {
            bmax[i] = mx;
            mx = max(mx, rowHeight[i]);
        }

        int ans = 0, sh;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sh = INT_MAX;

                sh = min(lmax[j], min(rmax[j], min(tmax[i], bmax[i])));

                ans += max(0, sh - heightMap[i][j]);
            }
        }

        return ans;

    }
};