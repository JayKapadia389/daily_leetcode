class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int ,  vector<int>> m ;

        for(int x = 0 ; x < nums.size() ; x++){
            m[nums[x]].push_back(x);
        }

        sort(nums.begin() , nums.end());

        int i = 0 , j = nums.size() - 1 ;

        vector<int> ans(2,-1) ;

        while(i < j){

            if((nums[i] + nums[j]) == target){
                ans[0] = m[nums[i]][0];

                if(nums[i] == nums[j]){
                    ans[1] = m[nums[i]][1];
                }
                else{
                    ans[1] = m[nums[j]][0];
                }

                return ans ;
            }
            else if((nums[i] + nums[j]) < target){
                i++ ;
            }
            else{
                j-- ;
            }

        } 

        return ans ;

    }
};