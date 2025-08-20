class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3(nums1.begin() , nums1.begin()+m);

        int i = 0 , l = 0, r = 0;
        while(l < n && r < m){
            if(nums2[l] <= nums3[r]){
                nums1[i] = nums2[l];
                ++l;
            }
            else{
                nums1[i] = nums3[r];
                ++r;
            }
            ++i;
        }

        while(l < n){
            nums1[i] = nums2[l];
            ++i;
            ++l;
        }

        while(r < m){
            nums1[i] = nums3[r];
            ++i;
            ++r;
        }
    }
};