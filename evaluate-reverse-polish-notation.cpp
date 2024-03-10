class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<string> st ;
        int left , right , ans;

        for(int i = 0 ; i< tokens.size() ; i++){

            if(tokens[i] == "+" || tokens[i] == "-" || 
            tokens[i] == "*" || tokens[i] == "/" ){

                right = stoi(st.top()) ;
                st.pop() ; 
                left = stoi(st.top()) ;
                st.pop() ;

                if(tokens[i] == "+"){
                    ans = left + right ;
                }
                else if(tokens[i] == "-"){
                    ans = left - right ;
                }
                else if(tokens[i] == "*"){
                    ans = left * right ;
                }
                else{
                    ans = left / right ;
                }

                st.push(to_string(ans)) ;

            }
            else{
                st.push(tokens[i]) ;
            }
        }

        return stoi(st.top()) ;
        
    }
};