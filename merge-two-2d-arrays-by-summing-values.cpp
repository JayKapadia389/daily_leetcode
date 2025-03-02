class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {

        vector<vector<int>> ans;

        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;

        while (i != n && j != m) {
            if (nums1[i][0] == nums2[j][0]) {
                ans.push_back({ nums1[i][0] , nums1[i][1] + nums2[j][1] });
                ++i;
                ++j;
            }
            else if (nums1[i][0] < nums2[j][0]) {
                ans.push_back(nums1[i]);
                ++i;
            }
            else {
                ans.push_back(nums2[j]);
                ++j;
            }
        }

        if (i == n || j == m) {
            for (int k = i; k < n; ++k) {
                ans.push_back(nums1[k]);
            }
            for (int k = j; k < m; ++k) {
                ans.push_back(nums2[k]);
            }
        }

        return ans;

    }
};