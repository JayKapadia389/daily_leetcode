class Solution {
public:

    vector<int> nums2_ ;
    int n2_;

    int helper(long long x, long long v){

        int l = 0 , r = n2_ - 1 ; 
        while(l <= r){
            int mid = (l+r)/2 ; 
            if(x >= 0 && nums2_[mid] * x <= v ||
               x < 0 && nums2_[mid] * x > v ){
                l = mid + 1 ; 
            }
            else{
                r = mid - 1; 
            }
        }

        if( x >= 0 )
        return l ; 

        return n2_ - l ; 
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {

        nums2_ = nums2 ; 
        n2_ = nums2.size() ;
        
        long long l = - 1e10 , r = 1e10 ;
        long long v ; 

        while(l <= r){
            long long count = 0 ; 
            v = (l+r)/2 ; 

            for(auto x : nums1){
                count += helper(x , v) ; 
            }

            if(count < k){
                l = v + 1 ; 
            }
            else{
                r = v - 1 ; 
            }
        }

        return l ; 

    }
};