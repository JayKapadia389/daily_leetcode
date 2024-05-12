class Solution {
public:

    void core(int n , vector<string> board , vector<vector<string>> &ans , int i , int j){

        if(!isValid()){
            return ;
        }

        int y ;

        for(int x = i ; x < n ;x++){

            if(x == i){
                y = j+1 ;
            }
            else{
                y = 0 ;
            }

            for( ; y < n ;y++){
                
                core(n-1 , , ans , x , y) ;
            }
        }

        return ;

    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans ;
        string s = "";

        for(int i =0 ; i< n ;i++){
            s+="." ;
        } 

        vector<string> board ;

        for(int i =0 ; i< n ;i++){
            board.push_back(s) ;
        }

        core(n , board , ans , 0 , 0) ;

        return ans ;

    }
};