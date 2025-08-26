class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int area;
        int diag_sqr = INT_MIN;

        for(auto d : dimensions){
            int temp_diag_sqr = d[0]*d[0] + d[1]*d[1] ; 

            if(temp_diag_sqr > diag_sqr){
                area = d[0]*d[1];
                diag_sqr = temp_diag_sqr;
            }
            else if(temp_diag_sqr == diag_sqr){
                area = max(area , d[0]*d[1]);
            }
        }

        return area;
    }
};