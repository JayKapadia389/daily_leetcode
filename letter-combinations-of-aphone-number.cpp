class Solution {
public:

    string _digits ; 

    void core(int i , string acc , vector<string> &ans ,vector<vector<char>> m){

        if(_digits.length() == 0){
            return ;
        }

        if(i == _digits.length()){
            ans.push_back(acc) ;
            return ;
        }

        string c = _digits.substr(i,1) ;
        cout << c << " ";
        int num = stoi(c) ;
        cout << num << endl ;
        vector<char> vec = m[num] ;

        for(int j = 0 ; j < vec.size() ; j++){
            core(i+1, acc+vec[j] , ans , m) ;
        }

        return ;

    }

    vector<string> letterCombinations(string digits) {

        vector<vector<char>> m = {
        {},
        {},
    {'a','b','c'},
    {'d','e','f'},
    {'g','h','i'},
    {'j','k','l'},
    {'m','n','o'},
    {'p','q','r','s'},
    {'t','u','v'},
    {'w','x','y','z'}

    } ;

        _digits = digits ;

        vector<string> ans ;
        string acc = "";

        core(0 , acc ,ans , m) ;

        return ans ;
        
    }
};