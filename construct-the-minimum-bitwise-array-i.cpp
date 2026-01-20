class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        for(auto& num : nums){
            if(num == 2){
                num = -1;
                continue;
            } 

            int d = 1;
            while((num & d) != 0){
                d <<= 1;
            } 
            d >>= 1;
            num ^= d;
        }
        return nums;
    }
};