class Solution {
public:
    string makeFancyString(string s) {

        string acc = "" ;

        int c = 0 ;
        char prev = '-' ;

        for(auto i : s){

            if(prev == '-'){
                prev = i ;
                c = 1 ;
                acc += i ;
            }
            else{

                if(i == prev){
                    if(c!= 2){
                    acc+=i ;
                    ++c ;
                    }
                }
                else{
                    acc+= i ;
                    prev = i ;
                    c = 1 ;
                }

            }

        }

        return acc ;
        
    }
};