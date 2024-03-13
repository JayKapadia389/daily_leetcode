class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> st ;
        int s = temperatures.size() ;
        vector<int> ans(s) ;

        for(int i = 0 ;  i < s ; i++){

            if(st.empty()){
                st.push(i) ;
            }

            else{

                while(!st.empty() && (temperatures[i] > temperatures[st.top()])){
                    ans[st.top()] = i - st.top() ;
                    st.pop() ;
                }

                st.push(i) ;
            }

        }

        while(!st.empty()){
            ans[st.top()] = 0 ;
            st.pop() ;
        }

        return ans ;
    }   
};