Solution {
public:
    int maxDiff(int num) {

        string s = to_string(num);
        string t = s ; 

        size_t i = s.find_first_not_of('9') ; 
        if(i != string::npos){
            char ch = s[i] ; 

            replace(s.begin() , s.end(), ch , '9') ; 
        }

        if(t[0] != '1'){
            char ch = t[0] ; 
            replace(t.begin() , t.end(), ch , '1') ;
        }
        else{
            size_t i = t.find_first_not_of("10") ;
            if(i != string::npos){
                char ch = t[i]; 
                replace(t.begin() , t.end() , ch , '0') ; 
            }
        }

        return stoi(s) - stoi(t) ; 
        
    }
};