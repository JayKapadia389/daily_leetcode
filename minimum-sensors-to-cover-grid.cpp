class Solution {
public:
    int minSensors(int n, int m, int k) {

        int len = 2*k +1 ;
        int h_rem = n % len ;
        int h_q = n/len;
        if(h_rem != 0){
            h_q += 1;
        }

        int v_rem = m % len ;
        int v_q = m/len;
        if(v_rem != 0){
            v_q += 1;
        }
        
        return (h_q * v_q);
    }
};