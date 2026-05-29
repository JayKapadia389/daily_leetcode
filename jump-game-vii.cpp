class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();

        if(s[n-1] == '1') {
            return false;
        }

        vector<int> recent(n);
        recent[n-1] = n-1;

        for(int i = n - 2; i >= 0; --i){
            if(s[i] == '1'){
                recent[i] = recent[i + 1];
            }
            else{
                int lower_bound = i + minJump;
                int upper_bound = i + maxJump;

                if(lower_bound >= n){
                    recent[i] = recent[i + 1];
                    continue;
                }

                int recent_carrier = recent[lower_bound];
                if(recent_carrier <= upper_bound)){
                    recent[i] = i;
                }
                else{
                    recent[i] = recent[i + 1];
                }
            }
        }

        return recent[0] == 0;
    }
};