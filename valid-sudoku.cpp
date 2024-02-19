class Solution {

public:

    void refresh(map<char , bool> &m){

        for(auto &i : m){
            i.second = 0 ;
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        map<char , bool> exist ;

        for(int i = 0 ; i < 9 ; i++ ){
            for(int j = 0 ;  j < 9 ; j++){

                if(board[i][j] != '.'){
                    
                    if(exist[board[i][j]]){
                        return false ;
                    }
                    else{
                        exist[board[i][j]] = 1 ;
                    }

                }
            }

            refresh(exist);
        }

        for(int j = 0 ; j < 9 ; j++ ){
            for(int i = 0 ;  i < 9 ; i++){

                if(board[i][j] != '.'){
                    
                    if(exist[board[i][j]]){
                        return false ;
                    }
                    else{
                        exist[board[i][j]] = 1 ;
                    }

                }
            }

            refresh(exist);
        }

        for(int i = 0 ; i < 9 ; i = i + 3){

            for(int j = 0 ; j < 9 ; j = j + 3){
                
                for(int a = 0 ; a < 3 ; a++){

                   for(int b = 0 ; b < 3 ; b++){

                       if(board[i+a][j+b] != '.'){
                    
                            if(exist[board[i+a][j+b]]){
                                return false ;
                            }
                            else{
                                exist[board[i+a][j+b]] = 1 ;
                            }

                }
                   }


                }
                   refresh(exist) ;
            }

        }

        return true ;
        
    }
};