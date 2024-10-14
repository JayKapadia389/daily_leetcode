class Solution {
public:

    class TrieNode{
        public :
        TrieNode * arr[26] ;

        TrieNode(){
            for(int i =0 ; i< 26 ; i++){
                arr[i] = NULL ;
            }
        }
    };

    class Trie{
        public :

        TrieNode * root ;

        bool search(string s){

            TrieNode * curr = root;
            int idx ;
            int i = 0 ;

            while(true){

                idx = s[i] - 'a' ;

                if(!(curr->arr)[idx]){
                    return  false ;
                }

                if(i == (s.length() - 1)){
                    return true ;
                }

                curr = (curr->arr)[idx] ; 
                i++ ;

            }

            return false  ;
            
        }

        Trie(){
            root = new TrieNode() ;
        }
    };

    //visted dec
    vector<vector<bool>> visited_ ;
    //dir
    vector<vector<int>> dir_ = {
        {0,-1},
        {1,0},
        {0,1},
        {-1,0},
    };
    //m n
    int m , n ;
    //board

    void recc(TrieNode * curr , int x , int y , vector<vector<char>>& board){

        visited_[x][y] = 1 ;

        for(int i = 0 ; i< 4 ; i++){

            int newX = x + dir_[i][0];
            int newY = y + dir_[i][1];

            if(
                !(
                    ((newX < 0 )||(newX >= m )) || ((newY < 0 )||(newY >= n ))
                )
                &&
                !visited_[newX][newY]
            ){

                TrieNode * newNode = new TrieNode() ;

                int idx = board[newX][newY] - 'a';

                (curr->arr)[idx] = newNode ;

                recc(newNode , newX , newY , board) ;

            }

        }

        visited_[x][y] = 0 ;

        return ;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        m = board.size() ;
        n = board[0].size() ;

        vector<vector<bool>> visited(12, vector<bool>(12)) ;
        visited_ = visited ;

        Trie myTrie ;
        TrieNode * root = myTrie.root ;

        for(int i = 0 ; i < m ; i++){
            for(int j =0 ; j < n ; j++){

                int idx = board[i][j] - 'a' ;

                if((root->arr)[idx] == NULL){
                    (root->arr)[idx] = new TrieNode() ;
                }

                recc((root->arr)[idx] , i , j , board) ;

            }
        }

        vector<string> ansVec ;

        for(int i =0 ; i < words.size() ; i++){

            if(myTrie.search(words[i])){
                ansVec.push_back(words[i]) ;
            }

        }

        return ansVec ;


        
    }
};