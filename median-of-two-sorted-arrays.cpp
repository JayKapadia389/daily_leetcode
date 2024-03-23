class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        nums1.insert(nums1.end() , nums2.begin() , nums2.end()) ;

        sort(nums1.begin() , nums1.end()) ;

        float med ;
        int s = nums1.size() ;

        if(s%2 == 0){
            med = static_`cast<float>(nums1[s/2] + nums1[(s/2) -1])/2 ;
        }
        else{
            med = nums1[(s-1)/2] ;
        }

        return med ;

        
    }
};