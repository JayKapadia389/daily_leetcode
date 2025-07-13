class Solution {
public:
    string processStr(string s) {

        string ans = "" ; 

        for(auto ch : s){
            if(ch >= 97 && ch <= 122){
                ans += ch ; 
            }
            else if(ch == '*' && (ans.length() != 0)){
                ans = ans.substr(0 , ans.length() - 1) ; 
            }
            else if(ch == '#'){
                ans += ans ; 
            }
            else if(ch == '%'){
                string temp = "";
                for(int i = ans.length() -1  ; i >= 0 ; --i){
                    temp += ans[i] ; 
                }
                ans = temp ; 
            }
        }

        return ans ; 
        
    }
};