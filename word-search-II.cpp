

class Node{

    public : 
    Node * children[26] ;

    Node(){
        for(int i = 0 ; i< 26 ; i++){
            children[i] = NULL ;
        }
    }
};

class Trie{

    public : 
    Node * root ;

    Trie(){
        root = new Node() ;
    }

    bool search(string word){

        Node * temp = root ;
        int idx ;

        for(int i = 0 ; i < word.length() ; i++){

            idx = word[i] - 'a' ;

            if((temp->children)[idx] == NULL){
                return false ;
            }

            temp = (temp->children)[idx] ;

        }

        return true ;

    }
};

class Solution {
public:

    Trie myTrie() ;
    vector<vector<int>> visited ;
    vector<vector<char>>_board ;

    vector<vector<int>> dir ;

    vector<int> pair(2) ;

    int _m ,_n ;

    bool inVec(int i , int j){
        for(int x = 0 ; x < visited.size() ; x++){
            if(visited[x][0] == i && visited[x][1] == j){
                return true ;
            }
        }

        return false ;
    }

    Solution(){

        vector<int> inner;

        inner[0] = -1;
        inner[1] = 0;
        dir.push_back(inner);

        inner[0] = 0;
        inner[1] = 1;
        dir.push_back(inner);

        inner[0] = 1;
        inner[1] = 0;
        dir.push_back(inner);

        inner[0] = 0;
        inner[1] = -1;
        dir.push_back(inner);

    }

    void recc(Node * curr , int i , int j ){

        int idx;

        for(int x = 0 ; x < 4 ; x++){

            int newX = i + dir[x][0] ;
            int newY = j + dir[x][1] ;

            if(!(newX < 0 || newX == _m || newY < 0 || newY == _n
            || inVec(i,j))){

                idx = _board[newX][newY] - 'a' ;

                if((curr->children)[idx] == NULL){
                    (curr->children)[idx] = new Node() ;
                }

                pair[0] = newX;
                pair[1] = newY;

                visited.push_back(pair) ;

                recc((curr->children)[idx] , newX , newY) ;

            }

        }

        visited.pop_back() ;

        return ;

    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        int m = board.size() ;
        int n = board[0].size() ;

        _m = m;
        _n = n ;

        for(int i =0 ; i< m ; i++){
            _board.push_back(board[i]) ;
        }

        int idx ;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){

                idx = board[i][j] - 'a' ;

                if(((myTrie.root)->children)[idx] == NULL){
                    ((myTrie.root)->children)[idx] = new Node() ;
                }

                visited.push_back([i,j]) ;

                recc(((myTrie.root)->children)[idx] , i , j) ;

            }
        }

        vector<string> ans ;

        for(int i = 0 ; i< words.size() ; i++){
            if(myTrie.search(words[i])){
                ans.push_back(words[i]);
            }
        }

        return ans ;

    }
};