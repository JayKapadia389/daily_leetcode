class Solution {
public:
    void trim(string &s){
        s.erase(0,s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ')+1);
    }

    void remove_extra_space(string &s){
        size_t i = s.find(' ');
        while(i != std::string::npos){
            size_t j = s.find_first_not_of(' ',i);
            s.erase(i+1,j-i-1);
            i = s.find(' ', i+1);
        }
    } 

    void reverse_string(string& s){
        reverse(s.begin(), s.end());

        size_t i = 0;
        size_t j = s.find(' ');

        while(true){
            if(j != std::string::npos){
                reverse(s.begin()+i, s.begin()+j);
                i = j+1;
                j = s.find(' ', j+1);
            }
            else{
                reverse(s.begin()+i, s.end());
                break;
            }
        }
    }

    string reverseWords(string s) {
        trim(s);
        remove_extra_space(s);
        reverse_string(s);
        return s;
    }
};