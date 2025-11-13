class Solution {
public:
    int maxOperations(string s) {
        int n = s.length();
        int ans = 0;
        vector<int> v(n);

        if(s[n-1] == '0') v[n-1] = 1;

        for(int i = n-2; i >= 0; --i){
            if(s[i] == '0' && s[i+1] == '1'){
                v[i] = v[i+1] + 1;
            }
            else{
                v[i] = v[i+1];
            }

            if(s[i] == '1') ans += v[i];
        }

        return ans;
    }
};