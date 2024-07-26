#include <iostream>

using namespace std ;

class Node{

    public :

  Node* children[26];
  bool endOfWord ;  

  Node(){
    for(int i = 0 ; i < 26 ; i++){
        children[i] = NULL ;
    }
    endOfWord = false ;
  }
};

class Trie{

    public :

    Node * root ;

    Trie(){
        root = new Node() ;
    }
};

int main(){

Trie * myTrie = new Trie() ;

}


