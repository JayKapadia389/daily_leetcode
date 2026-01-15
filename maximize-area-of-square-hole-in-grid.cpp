class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int max_con_h = 1, max_con_v = 1, con = 1;

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        for(int i = 1; i < hBars.size(); ++i){
            if(hBars[i] == (hBars[i-1] + 1)){
                ++con;
            }
            else{
                con = 1;
            }
            max_con_h = max(max_con_h, con);
        }

        con = 1;
        for(int i = 1; i < vBars.size(); ++i){
            if(vBars[i] == (vBars[i-1] + 1)){
                ++con;
            }
            else{
                con = 1;
            }
            max_con_v = max(max_con_v, con);
        }

        int base = min(max_con_h, max_con_v) + 1;
        return pow(base,2);
    }
};