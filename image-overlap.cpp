#define PII pair<int, int>

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<PII> img1_pixels;
        vector<PII> img2_pixels;
        vector<vector<int>> freq(2*n - 1, vector<int>(2*n - 1, 0));
        int ans = 0;
        int OFFSET = n - 1;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(img1[i][j] == 1) {
                    img1_pixels.push_back({i, j});
                }

                if(img2[i][j] == 1) {
                    img2_pixels.push_back({i, j});
                }
            }
        }


        for(auto img1_pxl : img1_pixels) {
            for(auto img2_pxl : img2_pixels) {
                int dx = img1_pxl.first - img2_pxl.first;
                int dy = img1_pxl.second - img2_pxl.second;
                ans = max(ans, ++freq[dx + OFFSET][dy + OFFSET]);
            }   
        }

        return ans;
    }
};