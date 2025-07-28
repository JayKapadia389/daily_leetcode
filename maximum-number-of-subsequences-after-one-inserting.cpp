class Solution {
public:
    long long numOfSubsequences(string s) {

        long long base = 0;
        int n = s.length();

        vector<long long> preL(n,0);
        vector<long long> sufT(n,0);

        preL[0] = (s[0] == 'L');
        for(int i = 1 ; i < n ; ++i){
            if(s[i] == 'L'){
                preL[i] = preL[i-1] + 1;
            }
            else{
                preL[i] = preL[i-1];
            }
        }

        sufT[n-1] = (s[n-1] == 'T');
        for(int i = n-2 ; i >= 0 ; --i){
            if(s[i] == 'T'){
                sufT[i] = sufT[i+1] + 1;
            }
            else{
                sufT[i] = sufT[i+1];
            }
        }

        vector<long long> sufCT(n, 0);
        vector<long long> preLC(n, 0);

        for(int i = n-2 ; i >= 0 ; --i){
            if(s[i] == 'C'){
                sufCT[i] = sufCT[i+1] + sufT[i];
            }
            else{
                sufCT[i] = sufCT[i+1];
            }
        }

        for(int i = 1 ; i < n ; ++i){
            if(s[i] == 'C'){
                preLC[i] = preLC[i-1] + preL[i];
            }
            else{
                preLC[i] = preLC[i-1];
            }
        }

        for(int i = 0 ; i < n ; ++i){
            if(s[i] == 'L'){
                base += sufCT[i];
            }
        }    

        long long extra = 0;
        extra = extra < sufCT[0] ? sufCT[0] : extra ;  
        extra = extra < preLC[n-1] ? preLC[n-1] : extra ;   

        // try all positions of C.
        for(int i = 0; i < n-1; ++i){
            extra = extra < (preL[i]*sufT[i+1]) ? (preL[i]*sufT[i+1]) : extra;
        }

        return (base+extra);
    }
};