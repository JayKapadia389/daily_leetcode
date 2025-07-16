class Solution {
public:
    int maximumLength(vector<int>& nums) {

        int ans = 2 ; 
        int curr , cnt_even = 0 , n = nums.size(); 

        //even-odd
        curr = 1 ;
        bool e = ((nums[0] % 2) == 0);

        if(e){
            ++cnt_even;
        }

        for(int i =1 ; i < n ; ++i){

            if(nums[i] % 2 == 0){
                ++cnt_even ;
            }

            if(e && nums[i]%2 != 0){
                    ++curr ; 
                    e = 0 ; 
            }
            if(!e && nums[i]%2 == 0){
                ++curr ; 
                e = 1 ;
            }
        }
        ans = max(ans , curr) ; 
        ans = max(ans , max(cnt_even , n - cnt_even)) ; 

        return ans ;

    }
};