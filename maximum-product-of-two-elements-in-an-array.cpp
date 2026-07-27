class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n = nums.size(), mx1 = INT_MIN, mx2 = INT_MIN;

        for(int i = 0; i < n; ++i){
            int num = nums[i];

            if(num >= mx2){
                mx1 = mx2;
                mx2 = num;
            }
            else if(num >= mx1){
                mx1 = num;
            }
        }

        return (mx1 - 1) * (mx2 - 1);
    }
};