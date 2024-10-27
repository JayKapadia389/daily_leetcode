class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int m = matrix.size() ;
        int n = matrix[0].size() ;
        int ans = 0 ;

        for(int window = 1 ; window <= min(m , n) ; window++ ){

            for(int i = 0 ; i <= (m-window) ; i++){

                for(int j = 0 ; j <= (n-window) ; j++){

                    bool flag = 0;

                    for(int x = 0 ; x <window ;x++){

                        for(int y = 0 ; y <window ;y++){

                            if(matrix[i+x][j+y] == 0){
                                flag = 1 ;
                                break ;
                            }

                        }

                        if(flag == 1){
                            break ;
                        }

                    }

                    if(flag == 0){
                        ++ans ;
                    }

                }

            }

        }

        return ans ;
        
    }
};