#include <iostream>

using namespace std ;

class TrieNode{
    public : 

    TrieNode * arr[26] ;
    bool eow ;

    TrieNode(){
        for(int i = 0 ; i < 26 ; i++){
            arr[i] = NULL ;
        }

        eow = false ;
    }
};

class Trie{
    
    TrieNode * root ;

    public : 

    Trie(){
        root = new TrieNode() ;
    }
    
    void insert(string s){

        int i = 0 ;
        TrieNode * curr = root ;
        int idx ;

        while(true){

            idx = s[i] - 'a' ;

            if((curr->arr)[idx] == NULL){
                (curr->arr)[idx] = new TrieNode() ;
            }

            i++ ;
            curr = (curr->arr)[idx] ;

            if(i == s.length()){
                curr->eow =true ;
                return ;
            }

        }

        return ;
    }

    bool search(string s){

        TrieNode * curr = root ;
        int i = 0 ;
        int idx ;

        while(true){

            idx = s[i] - 'a' ;
            if((curr->arr)[idx] == NULL){
                return false ;
            }

            if(i == (s.length()- 1)){
               return ((curr->arr)[idx])->eow ;
            }

            i++ ;
            curr = (curr->arr)[idx] ;

        }

        return false ;
    } 

};

int main(){

    Trie myTrie ;

    myTrie.insert("jaya") ;

    cout << myTrie.search("jay") ;

}

