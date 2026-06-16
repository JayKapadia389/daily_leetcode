class Solution {
public:
    string processStr(string s) {
        string result = "";

        for(auto ch : s){
            if(ch == '*'){
                int len = result.size();
                if(len > 0)
                    result.erase(len - 1, 1);
            }
            else if(ch == '#'){
                result += result;
            }
            else if(ch == '%'){
                reverse(result.begin(), result.end());
            }
            if(ch >= 'a' && ch <= 'z'){
                result += ch;
            }
        }

        return result;
    }
};