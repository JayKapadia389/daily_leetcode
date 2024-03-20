class Solution {
public:
    int search(vector<int>& nums, int target) {

        int l = 0, r = nums.size() - 1  ;
        int m ;

        while(l <= r){

            m = (l+r)/2 ;

            if(target == nums[l]){
                return l ;
            }
            if(target == nums[m]){
                return m ;
            }
            if(target == nums[r]){
                return r ;
            }

            if(l == m){
                return -1 ;
            }

            if(nums[l] < nums[m] && nums[m] < nums[r]){

                if(nums[l] < target && target < nums[m]){
                    r = m - 1 ;
                    continue ;
                }
                if(nums[m] < target && target < nums[r]){
                    l = m + 1 ;
                    continue ;
                }
                return -1 ;

            }

            else if(nums[l] < nums[m] && nums[m] > nums[r]){

                if(nums[l] < target && target < nums[m]){
                    r = m - 1 ;
                    continue ;
                }
                if(nums[m] < target || target < nums[r]){
                    l = m + 1 ;
                    continue ;
                }
                return -1 ;

            }

            else if(nums[l] > nums[m] && nums[m] < nums[r]){

                if(nums[l] < target || target < nums[m]){
                    r = m - 1 ;
                    continue ;
                }
                if(nums[m] < target && target < nums[r]){
                    l = m + 1 ;
                    continue ;
                }
                return -1 ;

            }
        }

        return -1 ;
        
    }
};