class Solution {
public:

    vector<int> stars_ ; 
    int n_ ; 

    bool isValid(string& str){
        stack<char> s ; 

        for(auto ch : str){
            if(ch == '('){
                s.push(ch) ; 
            }
            else{
                if(s.empty()){
                    return false ; 
                }
                else{
                    s.pop() ; 
                }
            }
        }

        if(s.empty()){
            return true ; 
        }
        return false ; 
    }

    bool recc(string curr_str , int replacement_no){

        if(replacement_no == n_){
            return isValid(curr_str) ; 
        }

        int replace_idx = stars_[replacement_no] ; 

        string s1 = curr_str.substr(0, replace_idx) ; 

        string s2;

        if (replace_idx + 1 >= curr_str.length()) {
            s2 = "";
        } else {
            s2 = curr_str.substr(replace_idx + 1);
        }


        ++replacement_no ; 

        if(recc(s1+""+s2 , replacement_no)){
            return true ;
        }
        if(recc(s1+"("+s2 ,replacement_no)){
            return true ;
        }
        if(recc(s1+")"+s2 ,replacement_no)){
            return true ;
        }

        return false ; 
    }

    bool checkValidString(string s) {

        vector<int> stars ; 
        
        for(int i = 0 ; i < s.length() ; ++i){
            if(s[i] == '*'){
                stars.push_back(i) ; 
            }
        }

        n_ = stars.size() ; 
        stars_ = stars ; 

        return recc(s , 0) ; 

    }
};