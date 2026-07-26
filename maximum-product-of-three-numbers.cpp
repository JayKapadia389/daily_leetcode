// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(3, INT_MIN);
        vector<int> mn(2, INT_MAX);

        for(int i = 0; i < n; ++i) {
            int num = nums[i];

            if(num >= mx[2]){
                mx[0] = mx[1];
                mx[1] = mx[2];
                mx[2] = num;
            }
            else if(num >= mx[1]){
                mx[0] = mx[1];
                mx[1] = num;
            }
            else if(num >= mx[0]){
                mx[0] = num;
            }

            if(num <= mn[1]){
                mn[0] = mn[1];
                mn[1] = num;
            }
            else if(num <= mn[0]){
                mn[0] = num;
            }
        }

        int p1 = mx[0] * mx[1] * mx[2];
        int p2 = mx[2] * mn[0] * mn[1];

        return max(p1, p2);
    }
};