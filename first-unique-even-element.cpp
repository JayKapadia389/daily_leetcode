class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto num : nums){
            ++freq[num];
        }

        for(auto num : nums){
            if(((num%2) == 0) && (freq[num] == 1)){
                return num;
            }
        }

        return -1;
    }
};