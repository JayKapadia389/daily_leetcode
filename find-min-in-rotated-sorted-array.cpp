class Solution {
public:
    int findMin(vector<int>& nums) {

        int ans = INT_MAX ;

        int l = 0  , r = nums.size() -1  ;

        while(l <= r){

            int mid = (l +r)/2 ;

            if((nums[l] < nums[mid]) && (nums[mid] < nums[r])){
                r = mid -1 ;
            }
            else if((nums[l] < nums[mid]) && (nums[mid] > nums[r])){
                l = mid + 1;
            }

            else if((nums[l] > nums[mid]) && (nums[mid] < nums[r])){
                ans = min(ans , nums[mid]) ;
                r = mid -1  ;
            }
            else if((nums[l] == nums[mid]) && (nums[mid] < nums[r])){
                ans = min(ans , nums[mid]) ;
                return ans ;
            }
            else if((nums[l] == nums[mid]) && (nums[mid] > nums[r])){
                ans = min(ans , nums[r]) ;
                return ans ;
            
            }
            else if((nums[l] ==  nums[mid]) && (nums[mid] == nums[r])){
                ans = min(ans , nums[mid]) ;
                return ans ;
            }
        }

        return ans ;
        
    }
};