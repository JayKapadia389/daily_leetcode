class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 1;
        int n = nums1.size();
        int e = nums2[n];
        int e_steps = INT_MAX;

        for(int i = 0; i < n; ++i){
            int a = nums1[i], b = nums2[i];
            ans += abs(a - b);

            a = min(nums1[i], nums2[i]);
            b = max(nums1[i], nums2[i]);
            
            if(e >= a && e <= b){
                e_steps = 0;
            }
            else{
                e_steps = min(e_steps, 
                             min(abs(e - a), abs(e - b))
                             );
            }
        }

        return ans + e_steps;
    }
};