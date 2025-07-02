class Solution {
public:
    int numDecodings(string s) {

        if(s[0] == '0'){
            return 0;
        }

        int n = s.length()  , num; 

        vector<int> single_(n , 0);
        vector<int> double_(n , 0);
        single_[0] = 1;

        for(int i = 1 ; i < n ; ++i){

            int x = single_[i-1];
            int y = double_[i-1];
            single_[i] = s[i] == '0' ? 0 : x + y ; 
            double_[i] = ((num = stoi(s.substr(i-1,2))) >= 10 && num <= 26) ? x : 0 ;
        }

        return single_[n-1] + double_[n-1] ; 
    }
};