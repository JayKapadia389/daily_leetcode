class Solution {
public:

    bool isDuplicateCore(map<int , int> &m1 , vector<int> v){

        map<int , int > m2 ;
        for(int i = 0 ; i < 3 ; i++){
            m2[v[i]]++ ;
        }

        for(auto i : m1){
            if(!(i.second == m2[i.first])){
                return false ;
            }
        }

        return true ;
    }

    bool isDuplicate(vector<int> triplet , vector<vector<int>> ans){

        map<int , int > m1 ;
        for(int i = 0 ; i < 3 ; i++){
            m1[triplet[i]]++ ;
        }

        for(int i = 0  ; i < ans.size() - 1 ; i++){
            if(isDuplicateCore(m1 , ans[i])){
                return true ;
            }
        }

        return false ;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans ;

        if(nums.size() < 3){
            return ans ;
        }

        sort(nums.begin() , nums.end()) ;

        int target = 0 ;
        vector<int> triplet ;
        int t2 ;
        int s = nums.size() ;

        for(int i = 0  ; i <= s - 3 ; i++){

            t2 = target - nums[i] ;
            int l = i+1  ;
            int r = s - 1 ; 

            while(l < r){

                int sum2 = nums[l] + nums[r] ; 
                vector<int> triplet ;

                if(sum2 == t2){
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[l]);
                    triplet.push_back(nums[r]);

                    if(!isDuplicate(triplet , ans)){
                        ans.push_back(triplet) ;
                    }
                    l++ ;
                    r-- ;
                }
                else if(sum2 < t2){
                    l++ ;
                }
                else{
                    r-- ;
                }
            }
        }

        return ans ;
        
    }
};