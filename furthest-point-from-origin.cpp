class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int base = 0, wildcard = 0;
        for(auto move : moves){
            if(move == 'L'){
                --base;
            }
            else if(move == 'R'){
                ++base;
            }
            else{
                ++wildcard;
            }
        }

        return abs(base) + wildcard;
    }
};