class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        multiset<int , greater<int>> s ;
        vector<int> ans ;

        for(int i = 0 ; i < k ; i++){
            s.insert(nums[i]) ;
        }

        int l = 0 , r = k-1 ;

        ans.push_back(*(s.begin())) ;

        for(l = 1 , r = k ; r < nums.size() ; l++ , r++){

            s.erase(s.find(nums[l-1])) ;
            s.insert(nums[r]) ;

            ans.push_back(*(s.begin())) ;

        }

        return ans ;
        
    }
};