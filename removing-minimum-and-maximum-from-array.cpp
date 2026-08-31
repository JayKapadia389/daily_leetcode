class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return 1;
        }

        int mn_idx = -1, mx_idx = -1;
        int mn_ele = INT_MAX, mx_ele = INT_MIN;

        for(int i = 0; i < n; ++i){
            int num = nums[i];

            if(num < mn_ele){
                mn_ele = num;
                mn = i;
            }
            
            if(num > mx_ele){
                mx_ele = num;
                mx = i;
            }            
        }

        if(mn > mx){
            swap(mn, mx);
        }

        int ans = min({
            mn + 1 + n - mx,
            mx + 1,
            n - mn
        });

        return ans;
    }
}