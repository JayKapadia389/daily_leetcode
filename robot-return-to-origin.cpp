class Solution {
public:
    bool judgeCircle(string moves) {
        int horizontalMovement = 0;
        int verticalMovement = 0;

        for(auto move : moves){
            if(move == 'U'){
                ++verticalMovement; 
            }
            else if(move == 'D'){
                --verticalMovement; 
            }
            else if(move == 'L'){
                ++horizontalMovement; 
            }
            else{
                --horizontalMovement;
            }
        }

        return horizontalMovement == 0 && verticalMovement == 0;
    }
};  