class Solution {
public:
    int findLHS(vector<int>& nums) {

        int ans = 0 , n = nums.size(); 
        sort(nums.begin() , nums.end()) ; 

        map<int , pair<int,int>> m ;
        int curr = nums[0] ; 
        m[curr].first = 0;

        for(int i = 1 ; i < n ; ++i){
            if(nums[i] != curr){
                m[curr].second = i-1 ;
                curr = nums[i];
                m[curr].first = i ; 
            }
        }

        m[curr].second = n-1 ; 

        auto it = m.begin() ;
        auto prev_value = it->first ;
        auto prev_pair = it->second ;
        ++it;

        for(; it != m.end() ; ++it){
            if(abs((it->first) - prev_value) == 1){
                ans = max(ans , (it->second).second - prev_pair.first + 1  );
            }
                prev_value = it->first ;
                prev_pair = it->second ;
        }

        return ans ; 
        
    }
};