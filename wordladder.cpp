class Solution {
public:

    string bw ;
    string ew ; 
    vector<string> wl ; 
    int ans = 0 ;
    vector<bool> visited ;
    int n ;
    int sl ;

    bool trans(string first , string second){

        bool set = 0 ;

        for(int i = 0 ; i < sl ; i++){
            if(first[i] != second[i]){
                if(set){
                    return false ;
                }
                else{
                    set = 1 ;
                }
            }
        }

        return true ;

    }

    bool recc(string word , int len , int wordIdx){

        if(word == ew){
            if(ans == 0 ){
                ans = len ;
            }
            else{
                ans = min(ans , len) ;
            }
            return true ;
        }

        for(int i = 0 ; i < n ; i++){

            if(!visited[i]){
                if(trans(word , wl[i]))
                {
                    visited[i] = 1 ;
                    if(!recc(wl[i] , len+1 , i)){
                        return false ;
                    }
                }
            }

        }

        if(wordIdx != -1)
        visited[wordIdx] = 0 ;

        return true ;

    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        n = wordList.size() ;
        vector<bool> temp(n , 0) ;
        visited = temp ;
        int first = -1 ;
        sl = beginWord.length() ;

        for(int i = 0 ; i<n ; i++){
            if(wordList[i] == beginWord){
                visited[i] = 1 ;
                first = i ;
                break ;
            }
        }

        recc(beginWord , 0 , first) ;

        return ans ;
        
    }
};