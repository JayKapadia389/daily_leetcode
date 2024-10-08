class Solution {
public:

    map<int , int> freq ;
    vector<vector<int>> ans ;
    int target_ ;

    void fun(map<int , int>::iterator it , int n , vector<int> v , int sum){

        for(int i = 0 ; i < n ; i++){
            v.push_back(it->first) ;
            sum += (it->first) ;
        }

        if(sum == target_){
            ans.push_back(v) ;
            return ;
        }
        else if(sum > target_){
            return ;
        }
        else{

            it++ ;

            if(it == freq.end()){
                return ;
            }
            else{
                for(int i =0 ; i <= it->second; i++){
                    fun(it , i , v , sum) ;
                }

                return ;
            }

        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        freq.clear() ;
        ans.clear() ;
        target_ = target ;

        sort(candidates.begin() , candidates.end()) ;

        //map
        for(int i =0 ; i < candidates.size() ; i++){
            freq[candidates[i]]++ ;
        }

        vector<int> v ;
        map<int , int>::iterator it = freq.begin();

        for(int i = 0 ; i <= it->second ; i++){
            fun(it , i , v , 0) ;
        }

        return ans ;

    }
};