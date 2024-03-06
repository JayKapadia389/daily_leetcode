class Solution {
public:
    int maxArea(vector<int>& height) {

        int ans = 0  ;

        for(int i = 0 ; i < height.size() -1  ; i++){
            bool flag = 1 ;
            for(int j = height.size() -1  ; (j > i) && flag  ; j--){

                ans = max(ans , min(height[i], height[j])* (j-i)) ;

                if(height[j] >= height[i]){
                    flag = 0 ;
                }
            }
        }

        return ans ;
        
    }
};