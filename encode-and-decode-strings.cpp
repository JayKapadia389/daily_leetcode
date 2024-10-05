class Solution {
public:

    string encode(vector<string>& strs) {

        string acc = "" ;

        for(int i = 0 ; i < strs.size() ; i++){

            acc += to_string(strs[i].length()) + "#" ;
            acc += strs[i] ;

        }

        return acc ;

    }

    vector<string> decode(string s) {

        vector<string> strs ;

        string num = "" ;

        for(int i = 0 ; i < s.length() ; i++){

            if(s[i] == '#'){
                
                strs.push_back(s.substr(i+1 , stoi(num))) ;
                i = i + stoi(num) ;
                num = "" ;

            }
            else{

                num += s[i] ;

            }


        }

        return strs ;

    }
};
