class Node{

    public : 

    Node * children[26] ;
    bool eow ;

    Node(){
        for(int i = 0 ; i < 26 ; i++){
            children[i] = NULL ;
        }
        eow = false ;
    }
};

class Trie {
public:

    Node * root ;

    Trie() {
        root = new Node() ;
    }
    
    void insert(string word) {

        Node * temp = root;
        int idx ;

        for(int i =0 ; i < word.length() ; i++){

            int idx = word[i] - 'a' ;

            if((temp->children)[idx] == NULL){
                (temp->children)[idx] = new Node() ;
            }

            temp = (temp->children)[idx] ;
        }

        temp->eow = true ;

        return ;
        
    }
    
    bool search(string word) {

        Node * temp = root;
        int idx ;

        for(int i = 0 ; i < word.length() ; i++){

            idx = word[i] - 'a' ;

            if((temp->children)[idx] == NULL){
                return false ;
            }
            else{

                if(i == (word.length() - 1)){
                    return ((temp->children)[idx]->eow) ;
                }

            }

            temp = (temp->children)[idx] ;

        }

        return false ;
        
    }
    
    bool startsWith(string prefix) {

        Node * temp = root;
        int idx ;

        for(int i = 0 ; i < prefix.length() ; i++){

            idx = prefix[i] - 'a' ;

            if((temp->children)[idx] == NULL){
                return false ;
            }

            temp = (temp->children)[idx] ;

        }

        return true ;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */