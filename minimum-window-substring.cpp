class Solution {
public:
    string minWindow(string s, string t) {

        int minLen = INT_MAX ;
        string ans = "" ;

        map<char , int> constFreq ;
        for(int i = 0 ; i < t.length() ; i++){

            constFreq[t[i]]++ ;

        }

        map<char , int> varFreq ;

        int j = 0 ;

        while(j < s.length()){

            varFreq[s[j]]++ ;

            if(constFreq[s[j]]){

                bool b = 0 ;

                for(auto y : varFreq){
                    if(constFreq[y.first] > y.second){
                        b = 1 ;
                        break ;
                    }
                }

                if(b == 0){
                    break ;
                }

            }

            j++ ;
            

        }

        if(j >= s.length()){
            return "" ;
        }

        int i = 0 ;

        bool shrink = 1 ;

        while(j<n){

            if(shrink){

                if(minLen > (j - i + 1)){
                    minLen = (j - i + 1) ;
                    ans = s.substr(i , j - i + 1) ;
                }

                

            }
            else{

            }

        }

        return ans ;

    }
};  