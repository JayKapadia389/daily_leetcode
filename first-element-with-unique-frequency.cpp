// contest
// not upsolved
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        vector<int> freq(1e5 + 1, 0);

        for(auto num : nums){
            ++freq[num];
        }
        
        unordered_set<int> occured;
        unordered_set<int> repeated;
        
        for(auto f : freq){
            if(!occured.contains(f)){
                occured.insert(f);
            }
            else{
                repeated.insert(f);
            }
        }

        for(auto num : nums){
            if(!repeated.contains(freq[num])){
                return num;
            }
        }

        return -1;
    }
};