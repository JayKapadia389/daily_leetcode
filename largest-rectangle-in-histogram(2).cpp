class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size() ;
        vector<int> left(n) , right(n) ;
        stack<int> st ;

        left[0] = -1 ;
        right[n-1] = n ;

        st.push(0) ;

        for(int i = 1 ; i < n ; i++ ){

            while(!st.empty()){

                if(heights[st.top()] < heights[i]){
                    left[i] = st.top() ;
                    break ;
                }

                st.pop() ;

            }

            if(st.empty()){
                left[i] = -1;
            }

            st.push(i) ;
        }

        while(!st.empty())
            st.pop() ;
        
        st.push(n-1) ;

        for(int i = n-2 ; i >=0  ; i-- ){

            while(!st.empty()){

                if(heights[st.top()] < heights[i]){
                    right[i] = st.top() ;
                    break ;
                }

                st.pop() ;

            }

            if(st.empty()){
                right[i] = n;
            }

            st.push(i) ;


        }

        int ans = 0 ;

        for(int i = 0 ; i < n ; i++){

            ans = max(ans , heights[i]*(right[i] - left[i] - 1)) ;

        }

        return ans ;
        

    }
};