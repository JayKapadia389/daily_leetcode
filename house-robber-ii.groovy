class Solution {
public:

    int linearRobber(vector<int>& nums , bool b){
        vector<int> nums2 ;

        if(b){
            nums2 = vector<int>(nums.begin() , nums.end() -1);
        }
        else{
            nums2 = vector<int>(nums.begin() + 1 , nums.end());
        }

        int n = nums2.size() ;
        if(n == 1){
        return nums2[0] ; 
        }

        vector<int> collection(n, 0);
        if(n > 2){
            collection[2] = collection[0] + nums2[0] ; 
        }

        for(int i = 3 ; i < n ; ++i){
            collection[i] = max(collection[i-2] + nums2[i-2],
                                collection[i-3] + nums2[i-3]);
        }

        return max(collection[n-1] + nums2[n-1],
                                collection[n-2] + nums2[n-2]);

    }

    int rob(vector<int>& nums) {
        
        int ans = 0, n = nums.size() ; 

        if(n == 1)
        return nums[0] ; 

        ans = max(linearRobber(nums , 0) , linearRobber(nums , 1));
        return ans ; 
    }
};