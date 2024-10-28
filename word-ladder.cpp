class Solution {
public:

    bool can(string s1 , string s2){

        int diff = 0;

        for(int i = 0 ; i < s1.length() ; i++){

            if(s1[i] != s2[i]){
                ++diff ;
            }
            if(diff > 1){
                return false ;
            }

        }

        return true ;

    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        int n = wordList.size() ;

        int i ;

        for( i = 0 ; i < n ; i++){

            if(wordList[i] == endWord){
                break ;
            }

        }   

        if(i == n){
            return 0;
        }

        vector<bool> visited(n , 0) ;
        vector<int> dis(n , -1);

        queue<string> q ;
        q.push(wordList[i]) ;
        q.push("") ;
        visited[i] = 1 ;
        dis[i] = 0 ;
        int base = 0 ;

        while(!q.empty()){

            while(true){

                string top = q.front() ;
                q.pop();

                if(top == ""){

                    if(!q.empty()){
                        q.push("") ;
                    }
                    break ;
                }

                //body
                for(int j = 0 ; j < n ; j++){

                    if(!visited[j] && can(top,wordList[j])){
                        visited[j] = 1;
                        dis[j] = base+1 ;
                        q.push(wordList[j]) ;
                    }

                }

            }

            ++base ;

        }

        //check if begin word in wordlist
        int k ;
        for(k = 0 ; k< n ; k++){

            if(wordList[k] == beginWord){
                break ;
            }

        }

        if(k != n){
            return dis[k]+1;
        }

        int ans = INT_MAX ;

        for(int j = 0 ; j < n ; j++){

            if(dis[j] != -1){

                if(can(beginWord , wordList[j])){
                    ans = min(ans , dis[j]+2) ;
                }

            }

        }

        if(ans == INT_MAX){
            return 0 ;
        }
        else{
            return ans ;
        }

    }
};