class Solution {
public:

    map<int , int> freq ;
    vector<vector<int>> ans ;

    void fun( map<int,int>::iterator it , int n , vector<int> vec){

        for(int i = 1 ; i <= n ; i++ ){
            vec.push_back(it->first) ;
        }

        it++;
        if(it == freq.end()){
            ans.push_back(vec) ;
            return ;
        }

        for(int i = 0 ; i <= (it->second) ; i++){
            fun(it , i , vec) ;
        }

        return ;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        freq.clear() ;
        ans.clear() ; 

        if(nums.size() == 0){
            return ans ;
        }

        sort( nums.begin() , nums.end()) ;

        for(int i = 0 ; i < nums.size() ; i++){
            freq[nums[i]]++ ;
        }

        auto it = freq.begin() ;

        vector<int> v ;

        for(int i = 0 ; i <= it->second ; i++){
            fun(it , i , v) ;
        }

        return ans ;
        
    }
};