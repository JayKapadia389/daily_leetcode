class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {

        // int n = nums.size() ; 

        sort(nums.begin() , nums.end()) ; 

        int min = nums[0], seq = 1 ;  

        for(auto it = nums.begin()+1 ; it < nums.end() ; ++it){
            if(abs(*it - min) > k){
                ++seq ; 
                min = *it ; 
            }
        }

        return seq ; 
        
    }
};