class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        set<int> s;
        unordered_map<int, int> freq;
        int threshold = nums.size()/3;

        for(auto num : nums){
            ++freq[num];
            if(freq[num] > threshold){
                s.insert(num);
            }
        }

        return vector<int>(s.begin() , s.end());
    }
};