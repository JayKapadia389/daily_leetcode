class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {

        vector<string> ans ;
        int n = s.length() ;  

        for(int i = 0 ; i < n ; i+=k){
            ans.push_back(s.substr(i , k));
        }

        string last = ans[ans.size() - 1] ; 
        int num_x_insert = k - last.length() ; 

        for(int i =0 ; i < num_x_insert ; ++i){
            last+=fill ; 
        }

        ans.pop_back() ; 
        ans.push_back(last) ; 
        return ans ; 
        
    }
};