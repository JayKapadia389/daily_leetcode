class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        int n = nums.size() ; 
        vector<vector<int>> ans ; 

        sort(nums.begin() , nums.end()) ; 

        for(auto i = nums.begin() ; i < nums.end() ; i+=3 ){
            if(abs(*i - *(i+2)) > k){
                return vector<vector<int>>() ; 
            }

            ans.push_back(vector<int>( i , i+3 )) ; 
        }

        return ans ; 

    }
};