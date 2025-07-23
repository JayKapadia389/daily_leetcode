class Solution {
public:
    string makeFancyString(string s) {
        if(s.length()<3)
            return s;

        string ans = "";
        ans.reserve(s.length());
        ans+=s[0];
        ans+=s[1];

        for(int i = 2 ; i < s.length(); ++i){
            if(!(s[i] == s[i-1] && s[i] == s[i-2]))
                ans+=s[i];
        }
        return ans ; 
    }
};