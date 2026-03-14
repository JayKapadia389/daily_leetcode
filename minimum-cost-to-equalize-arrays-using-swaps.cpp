class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        vector<int> total_freq(8e4 + 1);
        vector<int> num1_freq(8e4 + 1);
        int n = nums1.size();
        
        for(int i = 0; i < n; ++i){
            ++num1_freq[nums1[i]];
            ++total_freq[nums1[i]];
            ++total_freq[nums2[i]];
        }

        int sum = 0;
        for(int i = 1; i <= 8e4; ++i){
            if(total_freq[i] & 1){
                return -1;
            }

            sum += abs(total_freq[i]/2 - num1_freq[i]);
        }

        return sum/2;
    }
};