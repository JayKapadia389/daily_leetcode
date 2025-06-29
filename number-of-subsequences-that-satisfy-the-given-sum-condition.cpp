int mod = 1e9 + 7;

class Solution {
public:

    int mod_pow(int exp) {
        long long result = 1;
        long long b = 2;
        while (exp > 0) {
            if (exp % 2 == 1)
                result = (result * b) % mod;
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }

    int numSubseq(vector<int>& nums, int target) {

        sort(nums.begin() , nums.end()) ; 

        int l = 0 , r = nums.size() - 1 ; 
        int ans = 0 ;

        while(l <= r){

            if(nums[l] + nums[r] <= target){
                ans = (ans + mod_pow(r - l))% mod ; 
                ++l ; 
            }
            else{
                --r ;
            }

        }
        return ans ; 
        
    }
};