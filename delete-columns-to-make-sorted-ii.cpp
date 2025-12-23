class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), len = strs[0].length(), del = 0;
        vector<string> base(n , "");
        for(auto& s : base){
            s.reserve(100);
        }
        
        // all chars
        for(int i = 0; i < len; ++i){
            bool equal = 0, rev = 0;
            // all strings
            for(int j = 0; j < n-1; ++j){
                string top = base[j] + strs[j][i];
                string bottom = base[j+1] + strs[j+1][i];
                if(top > bottom){
                    rev = 1;
                    break;
                }
                else if(top == bottom){
                    equal = 1;
                }
            }

            if(!rev && !equal){
                return del;
            }
            else if(rev){
                ++del;
            }
            else{
                for(int j = 0; j < n; ++j){
                    base[j] += strs[j][i];
                }
            }
        }

        return del;
    }
};