class Solution {
public:
    vector<string> partitionString(string s) {

        map<string , bool> m ; 

        string curr = "" ; 
        int n = s.length();
        vector<string> ans ; 
        
        for(int i = 0 ; i < n ; ++i){

            curr += s[i] ; 

            if(m[curr] != 1){
                m[curr] = 1 ; 
                ans.push_back(curr) ; 
                curr = "" ; 
            }
            
        }

        return ans ;
        
    }
};