class Solution {
public:

    bool isPrime(int i){
        if(i == 0 || i == 1){
            return false; 
        }

        for(int j = 2; j <= sqrt(i) ; ++j){
            if(i % j == 0){
                return false ; 
            }
        }

        return true;
    }
    
    long long splitArray(vector<int>& nums) {

        long long first = 0, second = 0 ; 

        for(int i = 0 ; i < nums.size() ; ++i){
            if(isPrime(i)){
                first+=nums[i] ; 
            }
            else{
                second+= nums[i] ; 
            }
        }

        return abs(first - second) ; 
    }
};