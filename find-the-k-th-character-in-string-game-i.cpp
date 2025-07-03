class Solution {
public:

    string s;

    Solution(){
        s = "a";
        for(int i = 0 ; i < 9 ; ++i ){
            string e = "";

            for(auto ch : s){
                if(ch < 122){
                    e += static_cast<char>(ch+1) ; 
                }
                else{
                    e += 'a' ; 
                }
            }
            s += e ;
        }
    }

    char kthCharacter(int k) {
        return s[k-1] ; 
    }
};