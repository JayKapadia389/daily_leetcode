class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), cnt = 0;
        int len = strs[0].length();

        for(int i = 0; i < len; ++i){
            for(int j = 0; j < n - 1; ++j){
                if(strs[j][i] > strs[j+1][i]){
                    ++cnt;
                    break;
                }
            }
        }
        return cnt;
    }
};