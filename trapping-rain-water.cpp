class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size() ;

        vector<int> l(n) , r(n) ;

        int ans = 0  ;
        int mx ;    

        for(int i = 0 ; i < n ; i++){

            if(i==0){
                l[0] = 0 ;
                mx = 0 ;
            }

            else{
                
                l[i] = mx ;

                if(height[mx] < height[i]){

                    mx = i ;

                }

            }
        }

        for(int i = n-1 ; i >= 0 ; i--){

            if(i==n-1){
                r[n-1] = 0 ;
                mx = n-1 ;
            }

            else{
                
                r[i] = mx ;

                if(height[mx] < height[i]){

                    mx = i ;

                }

            }
        }

        int mnHeight ; 

        for(int i = 0 ; i < n ; i++){

            if(i == 0 || i== n-1){
                continue ;
            }
            else{


                mnHeight = min(height[l[i]] , height[r[i]]) ;

                if(mnHeight > height[i]){
                    ans += (mnHeight - height[i]) ;
                }

            }

        }

        return ans ;
        
    }
};