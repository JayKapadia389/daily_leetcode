class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";

        while(num != 0){
            int curr = 0;
            
            if(sum != 0){
                curr = min(sum, 9);
                sum -= curr;
            }

            s += (curr + '0');
            --num;
        }

        if(sum != 0){
            return "";
        }

        return s;
    }
};