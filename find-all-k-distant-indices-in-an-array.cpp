class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        int n = nums.size() ; 
        int prev = -1 ; 
        vector<int> left(n , -1) ; 
        vector<int> right(n , -1) ; 

        for(int i = 0 ; i < n; ++i){
            if(nums[i] == key){
                prev = i ; 
            }

            left[i] = prev ; 
        }

        prev = -1 ;
        
        for(int i = n-1 ; i >= 0 ; --i){
            if(nums[i] == key){
                prev = i ; 
            }

            right[i] = prev ; 
        }

        vector<int> ans ; 

        for(int i = 0 ; i < n ; ++i){
            if(left[i] != -1 && abs(left[i] - i) <= k){
                ans.push_back(i) ; 
            }
            else if(right[i] != -1 && abs(right[i] - i) <= k){
                ans.push_back(i) ; 
            }
        }

        return ans ;
    }
};