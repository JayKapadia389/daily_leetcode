class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int s_e = INT_MAX, s_o = INT_MAX;

        for(auto num : nums1) {
            if(num % 2 == 0){
                s_e = min(s_e, num);
            }
            else {
                s_o = min(s_o, num);
            }
        }

        return s_e == INT_MAX || s_o == INT_MAX || (s_e - s_o >= 1);
    }
};