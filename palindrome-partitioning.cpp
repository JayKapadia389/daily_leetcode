class Solution {

public:
    string _s ;

    bool palindrome(int st ,int e ){

            int l = st ;
            int r = e ;

            while(l <= r){
                if(_s[l] != _s[r]){
                    return false ;
                }
                l++ ;
                r-- ;
            }

            return true ;
    }

    vector<string> getVec(vector<int> cuts){

        vector<string> acc ;

        if(cuts.empty()){
            acc.push_back(_s) ;
            return acc;
        }

        int st = 0;
        
        for(int i = 0 ; i < cuts.size() ; i++){
            int y = cuts[i] ;

            acc.push_back(_s.substr(st , y - st + 1))  ;

            st = y+1;

        }

        acc.push_back(_s.substr(st ,( _s.length() - 1) - st + 1)) ;

        return acc ;
    }

    void core(int m , vector<int> cuts , int st  ,vector<vector<string>> &ans){

        if(m == 0){
            if(palindrome(st , _s.length() -1 )){

                ans.push_back(getVec(cuts)) ;
            } 
                return ;
        }

        for(int i = st ; i <= (_s.length() -1 -m) ; i++){

            vector<int> temp = cuts ;
            temp.push_back(i) ;

            if(palindrome(st , i )){
                core(m-1 ,temp , i+1 ,ans  ) ;
            }
        }

        return ;

    }

    vector<vector<string>> partition(string s) {

        _s = s ;
        vector<vector<string>> ans ;
        vector<int> cuts ;

        for(int i = 0 ; i < s.length() ; i++){
            core(i  , cuts , 0 , ans ) ;
        }

        return ans ;
        
    }
};