class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int threshold = nums.size()/2 ; 

        for(auto num : nums){
            ++freq[num];
            if(freq[num] > threshold)
                return num;
        }
        return 0;
    }
};