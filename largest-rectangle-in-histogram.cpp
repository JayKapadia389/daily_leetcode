class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int h = 0 ;
        int ans = 0 ; 

        for(int i = 0  ; i < heights.size() ; i++){
            if(heights[i] > h ){
                h = heights[i] ;
            }
        }

        for(int i = 1  ; i <= h ; i++){

            int l = 0 ;

            for(int j = 0 ; j < heights.size() ; j++ ){

                if(heights[j] < i ){
                    l =0 ;
                    continue ; 
                }

                else{
                    l++ ;
                    ans = max(ans , l * i) ; 
                }
            }
        }

        return ans ;

    }
};