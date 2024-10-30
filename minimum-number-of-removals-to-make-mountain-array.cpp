class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {

        int n = nums.size() ;

        vector<int> left(n , 0) ;
        vector<int> right(n , 0) ;
        int l ;

        for(int i = 0 ; i < n ; i++){

            l = 0;

            for(int j = 0 ; j < i ; j++){

                if(nums[j] < nums[i]){
                    l = max(l , left[j] +1 ) ;
                }

            }

            left[i] = l ;

        }

        for(int i = n-1 ; i >= 0 ; i--){

            l = 0;

            for(int j = n-1 ; j > i ; j--){

                if(nums[j] < nums[i]){
                    l = max(l , right[j] +1 ) ;
                }

            }

            right[i] = l ;

        }


        int ans = 0 ;

        for(int i = 0 ; i< n ; i++){

            if(left[i] && right[i]){
                ans = max(ans , left[i]+1+right[i]) ;
            }

        }

        return (n-ans) ;

        
    }
};