class Solution {
public:

    bool anag(string s1 , string s2){

        map<char , int> fs1 , fs2 ;

        if(s1.length() != s2.length()){
            return false ;
        }

        for(int i = 0 ; i < s1.length() ; i++){
            fs1[s1[i]]++ ;

            fs2[s2[i]]++ ;
        }

        for(auto i : fs1){
            if(fs1[i.first] != fs2[i.first]){
                return false ;
            }
        }

        return true ;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> ans ;
        vector<int> ids ;
        vector<string> grp ;

        while(strs.size() != 0){

            ids.push_back(0) ;

            for(int i = 1 ; i < strs.size() ; i++){

                if(anag(strs[0] , strs[i])){
                    ids.push_back(i);
                }

            }

            for(int i = 0 ; i < ids.size() ; i++){
                grp.push_back(strs[ids[i]]);
            }

            ans.push_back(grp);

            int x = 0 ;

            for(int i = 0 ; i < ids.size() ; i++){

                strs.erase(strs.begin() + ids[i] - x);

                x++ ;
            }

            ids.clear();
            grp.clear();

        }

        return ans ;
        
    }
};