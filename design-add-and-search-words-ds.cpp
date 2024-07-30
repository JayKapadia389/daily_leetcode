class Node{

    public : 
    Node * children[26]; 
    bool eow ;

    Node(){
        for(int i = 0 ; i< 26 ; i++){
            children[i] = NULL ;
            eow = false ;
        }
    }
};

class WordDictionary {
public:

    Node * root ;

    WordDictionary() {

        root = new Node() ;
        
    }
    
    void addWord(string word) {

        Node * temp = root ;
        int idx ;

        for(int i = 0 ; i < word.length() ; i++){

            idx = word[i] - 'a' ;

            if((temp->children)[idx] == NULL){
                (temp->children)[idx] = new Node() ;
            }

            temp = (temp->children)[idx] ;
        }

        temp->eow = true ;
        
    }
    
    bool search(string word) {

        queue<Node *> q ;
        int idx ;

        q.push(root) ;
        q.push(NULL) ;

        Node * temp ; 

        for(int i = 0 ; i < word.length() ; i++){

            if(word[i] != '.'){

                idx = word[i] - 'a' ;

                while(q.front() != NULL){

                    temp = q.front() ;
                    q.pop() ;

                    if((temp->children)[idx] != NULL){
                        q.push((temp->children)[idx]) ;
                    }

                }

            }
            else{

                while(q.front() != NULL){

                    temp = q.front() ;
                    q.pop() ;

                    for(int i = 0 ; i< 26 ; i++){

                        if((temp->children)[i] != NULL){
                            q.push((temp->children)[i]) ;
                        }

                    }

                }

            }

            q.pop() ;

            if(q.empty()){
                return false ;
            }

            q.push(NULL) ;

        }

        while(q.front() != NULL){
            temp = q.front() ;
            q.pop();

            if(temp->eow){
                return true ;
            }
        }

        return false ;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */