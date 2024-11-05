class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int maxSum = INT_MIN  , curr = 0;

        for(int i =0 ; i < nums.size() ;i++){

            curr = max(0 , curr) ;

            curr+= nums[i] ;
            maxSum = max(curr , maxSum) ;

        }

        return maxSum ;

    }
};