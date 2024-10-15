class Solution {
public:

    class TrieNode{
        public :
        TrieNode * arr[26] ;
        bool eow ;

        TrieNode(){
            for(int i =0 ; i< 26 ; i++){
                arr[i] = NULL ;
            }

            eow = false ;
        }
    };

    class Trie{
        public :

        TrieNode * root ;

        void insert(string s){

            int idx ; 
            int i = 0 ;
            TrieNode * curr = root;

            while(true){

                idx = s[i] - 'a' ;

                if((curr->arr)[idx] == NULL){
                    (curr->arr)[idx] = new TrieNode() ;
                }

                curr = (curr->arr)[idx] ;
                i++ ;

                if(i == s.length()){
                    curr->eow = true ;
                    return ;
                }
            }

        }

        Trie(){
            root = new TrieNode() ;
        }
    };

    vector<vector<bool>> visited_ ;
    vector<vector<int>> dir_ = {
        {0,-1},
        {1,0},
        {0,1},
        {-1,0},
    };
    int m_ , n_ ;
    vector<string> ansVec_ ;

    void recc(TrieNode * curr , int x , int y , vector<vector<char>>& board , string str){

        visited_[x][y] = 1 ;

        str+= board[x][y] ;

        if(curr->eow){
            int cnt = count(ansVec_.begin(), ansVec_.end(), str);

            if (cnt == 0)
            ansVec_.push_back(str) ;
        }

        for(int i = 0 ; i< 4 ; i++){

            int newX = x + dir_[i][0];
            int newY = y + dir_[i][1];

            if(
                !(
                    ((newX < 0 )||(newX >= m_ )) || ((newY < 0 )||(newY >= n_ ))
                )
                &&
                !visited_[newX][newY]
            ){

                int idx = board[newX][newY] - 'a';

                if((curr->arr)[idx]){
                    recc((curr->arr)[idx] , newX , newY , board , str) ;
                }

            }

        }

        visited_[x][y] = 0 ;

        return ;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        Trie myTrie ;
        TrieNode * root = myTrie.root ;

        for(auto i : words){
            myTrie.insert(i) ;
        }

        m_ = board.size() ;
        n_ = board[0].size() ;

        vector<vector<bool>> visited(12, vector<bool>(12)) ;
        visited_ = visited ;
        ansVec_.clear() ;

        for(int i = 0 ; i < m_ ; i++){
            for(int j =0 ; j < n_ ; j++){

                int idx = board[i][j] - 'a' ;

                if((root->arr)[idx]){
                    recc((root->arr)[idx] , i , j , board, "") ;
                }
            }
        }

        return ansVec_ ;
 
    }
};