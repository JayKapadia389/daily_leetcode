class Solution {
public:

    bool isValid(string str , int n){

        if(str == ""){
            return true ;
        }
        
        int o = 0 , c = 0;

        for(int i = 0 ; i < str.length() ; i++){
            if(str[i] == '('){
                o++ ;
            }
            else{
                c++ ;
            }
        }

        if(n < o || c > o){
            return false ;
        }

        return true ;

    }

    void recc(vector<string> &ans , string str , int n){

        if(n == 0 ){
            return  ;
        }

        if(isValid(str , n)){

            if(str.length() == (2*n)){
                ans.push_back(str) ;
            }

            recc(ans , str+"(" , n);
            recc(ans , str+")" , n);

        } 
            return ;
    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> ans ;

        recc(ans , "" , n) ;

        return ans ;

    }
};