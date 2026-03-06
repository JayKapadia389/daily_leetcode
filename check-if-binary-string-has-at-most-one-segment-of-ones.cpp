class Solution {
public:
    bool checkOnesSegment(string s) {
        bool b = 1;
        int n = s.length(), i = 0;

        while(i < n && s[i] == '1'){
            ++i;
        }

        for(int j = i; j < n; ++j){
            if(s[j] == '1'){
                b = 0;
                break;
            }
        }

        return b;
    }
};