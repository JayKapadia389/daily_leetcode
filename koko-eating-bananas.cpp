class Solution {
public:

    bool isPossible(long long int mid , vector<int>& piles , int h){

        int tempHours = 0 ;

        for(int i = 0 ; i< piles.size() ; i++){
                tempHours += ceil(static_cast<double>(piles[i]) / mid);

                if(tempHours > h){
                    return false ;
                }
        }

        return true ;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        long long int maxB = 0 , ans = INT_MAX ;

        for(int i = 0 ; i< piles.size() ; i++){
            if(piles[i] > maxB){
                maxB = piles[i] ;
            }
        }
        
        long long int l = 1 , r= maxB;

        while(r >= l){

            long long int mid = l + (r - l) / 2; ;

            if(isPossible(mid , piles , h)){
                ans = mid ;
                r = mid - 1;
            }

            else{
                l = mid + 1;
            }
        }

        return ans ;
        
    }
};